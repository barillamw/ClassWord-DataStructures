#include "Graph.h"
#include "DList.h"
#include "IntegerSet.h"
#include "Queue.h"
#include "MinHeap.h"
#include <climits>
#include <stdio.h>

bool doesPathExist(ece309::Graph &g, int *path, int length) {
  for (int i = 0; i < length - 1; i++) {
    if (!g.isAdjacent(path[i], path[i + 1]))
      return false;
  }
  return true;
}

void visit(int node) { printf("%d ", node); }

void BreadthFirstSearch(ece309::Graph &graph, int start) {
  ece309::IntegerSetHT discovered(1000);
  ece309::Queue frontier;
  frontier.push(start);
  discovered.insert(start);
  while (!frontier.empty()) {
    int node = frontier.peek();
    visit(node);
    ece309::List adjList = graph.getAdjacencyList(node);
    ece309::List::iterator it = adjList.begin();
    while (!it.end()) {
      int j = it.getItem();
      if (!discovered.search(j)) {
        frontier.push(j);
        discovered.insert(j);
      }
      it.increment();
    }
    frontier.pop();
  }
}

void DepthFirstSearch_helper(ece309::Graph &g, ece309::IntegerSet &visitedSet, int node) {
  if (!visitedSet.search(node)) {
    visit(node); // take action upon visit to node
    visitedSet.insert(node);
    ece309::List adjList = g.getAdjacencyList(node);
    for (ece309::List::iterator it = adjList.begin(); !it.end(); it.increment())
      DepthFirstSearch_helper(g, visitedSet, it.getItem());
  }
}

void DepthFirstSearch(ece309::Graph &g, int node) {
  ece309::IntegerSetHT ht(1000);
  DepthFirstSearch_helper(g, ht, node);
}

void ece309::WeightedDenseGraph::addWeight(int from, int to, int weight) {
  weights[from * numNodes + to] = weight;
  weights[to * numNodes + from] = weight;
}

void ece309::WeightedDenseGraph::addEdge(int from, int to, int weight) {
  addEdge(from, to);
  addWeight(from, to, weight);
}

class node_helper {
public:
  node_helper() {
    distance = INT_MAX;
    pred = -1;
  }
  int distance;
  int pred;
};

node_helper *ShortestPath(ece309::Graph &g, int startV) {

  int numNodes = g.getNumNodes();
  node_helper *nodesH = new node_helper[numNodes];

  nodesH[startV].distance = 0;
  ece309::MinHeap unvisitedHeap;
  for (int i = 0; i < numNodes; i++){
    unvisitedHeap.insert(i);
  }

  for(int j=0; j<unvisitedHeap.getSize(); j++) {

    int currentV;
    unvisitedHeap.remove(currentV);
    int min_distance = nodesH[currentV].distance;

    ece309::List adjList = g.getAdjacencyList(currentV);
    for (ece309::List::iterator lit = adjList.begin(); !lit.end(); lit.increment()) {
      int toNode = lit.getItem();
      if (g.getWeight(currentV, toNode) + min_distance <
          nodesH[toNode].distance) {
        nodesH[toNode].distance = g.getWeight(currentV, toNode) + min_distance;
        nodesH[toNode].pred = currentV;
      }
    }
  }
  return nodesH;
}

node_helper *ShortestPathOrig(ece309::Graph &g, int startV) {

  int numNodes = g.getNumNodes();
  node_helper *nodesH = new node_helper[numNodes];

  nodesH[startV].distance = 0;
  ece309::DList unvisitedQueue;
  for (int i = 0; i < numNodes; i++)
    unvisitedQueue.append(i);

  while (!unvisitedQueue.empty()) {
    ece309::DList::iterator it = unvisitedQueue.begin();
    int min_node = it.getItem();
    ece309::DList::iterator min = it; // remember iterator to minimum
    int min_distance = nodesH[min_node].distance;

    while (!it.end()) {
      if (nodesH[it.getItem()].distance < min_distance) {
        min_node = it.getItem();
        min = it;
        min_distance = nodesH[min_node].distance;
      }
      it.increment();
    }

    int currentV = min_node;
    unvisitedQueue.erase(min); // remove min from queue

    ece309::List adjList = g.getAdjacencyList(currentV);
    for (ece309::List::iterator lit = adjList.begin(); !lit.end(); lit.increment()) {
      int toNode = lit.getItem();
      if (g.getWeight(currentV, toNode) + min_distance <
          nodesH[toNode].distance) {
        nodesH[toNode].distance = g.getWeight(currentV, toNode) + min_distance;
        nodesH[toNode].pred = currentV;
      }
    }
  }
  return nodesH;
}




int main() {

  ece309::SparseGraph g(14);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);

  g.addEdge(1, 4);
  g.addEdge(3, 5);
  g.addEdge(2, 6);
  g.addEdge(3, 6);
  g.addEdge(2, 7);
  g.addEdge(1, 8);
  g.addEdge(7, 8);
  g.addEdge(1, 9);
  g.addEdge(4, 10);
  g.addEdge(6, 11);
  g.addEdge(7, 12);
  g.addEdge(8, 13);

  /*  int path[3] = {0, 1, 9};
    if (doesPathExist(g, path, 3))
      printf("Exists!\n");*/

  printf("BFS(0)=");
  BreadthFirstSearch(g, 0);
  printf("\nBFS(13)=");

  BreadthFirstSearch(g, 13);

  printf("\nDFS(0): ");
  DepthFirstSearch(g, 0);

  printf("\nDFS(13): ");
  DepthFirstSearch(g, 13);

 ece309:: WeightedDenseGraph wg(6);
  wg.addEdge(0, 1, 450);
  wg.addEdge(0, 3, 150);
  wg.addEdge(0, 2, 370);
  wg.addEdge(1, 3, 550);
  wg.addEdge(2, 4, 210);
  wg.addEdge(3, 4, 370);
  wg.addEdge(3, 5, 340);
  wg.addEdge(2, 5, 130);
  wg.addEdge(4, 5, 5);

  printf("\nwg DFS(0): ");
  DepthFirstSearch(wg, 0);
  printf("\n\n");

  node_helper *nodesH = ShortestPath(wg, 0);
  node_helper *nodesHO = ShortestPathOrig(wg,0);

  printf("MinHeap Iterator\n");
  for (int j = 0; j < wg.getNumNodes(); j++) {
    printf("%d: dist=%d pred=%d \n", j, nodesH[j].distance, nodesH[j].pred);
  }
  printf("\nLinear Iterator\n");
  for (int k = 0; k < wg.getNumNodes(); k++) {
    printf("%d: dist=%d pred=%d \n", k, nodesHO[k].distance, nodesHO[k].pred);
  }

  return 0;
}
