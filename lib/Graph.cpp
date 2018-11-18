#include "Graph.h"
#include "DList.h"
#include "IntegerSet.h"
#include "Queue.h"
#include <climits>
#include <stdio.h>

SparseGraph::SparseGraph(int n) : Graph(n) { nodes = new Node[numNodes]; }

void SparseGraph::addEdge(int v1, int v2) {
  nodes[v1].edge.append(v2);
  nodes[v2].edge.append(v1);
}

bool SparseGraph::isAdjacent(int v1, int v2) const {
  List::iterator it = nodes[v1].edge.begin();
  while (!it.end()) {
    if (it.getItem() == v2) {
      return true;
    }
    it.increment();
  }
  return false;
}

DenseGraph::DenseGraph(int n) : Graph(n) {
  edges = new bool[numNodes * numNodes];
  for (int i = 0; i < numNodes * numNodes; i++)
    edges[i] = false;
}
void DenseGraph::addEdge(int v1, int v2) {
  edges[v1 * numNodes + v2] = true;
  edges[v2 * numNodes + v1] = true;
}

bool DenseGraph::isAdjacent(int v1, int v2) const {
  return edges[v1 * numNodes + v2];
}

bool doesPathExist(Graph &g, int *path, int length) {
  for (int i = 0; i < length - 1; i++) {
    if (!g.isAdjacent(path[i], path[i + 1]))
      return false;
  }
  return true;
}

void visit(int node) { printf("%d ", node); }

void BreadthFirstSearch(Graph &graph, int start) {
  IntegerSetHT discovered(1000);
  Queue frontier;
  frontier.push(start);
  discovered.insert(start);
  while (!frontier.empty()) {
    int node = frontier.peek();
    visit(node);
    List adjList = graph.getAdjacencyList(node);
    List::iterator it = adjList.begin();
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

void DepthFirstSearch_helper(Graph &g, IntegerSet &visitedSet, int node) {
  if (!visitedSet.search(node)) {
    visit(node); // take action upon visit to node
    visitedSet.insert(node);
    List adjList = g.getAdjacencyList(node);
    for (List::iterator it = adjList.begin(); !it.end(); it.increment())
      DepthFirstSearch_helper(g, visitedSet, it.getItem());
  }
}

void DepthFirstSearch(Graph &g, int node) {
  IntegerSetHT ht(1000);
  DepthFirstSearch_helper(g, ht, node);
}

void WeightedDenseGraph::addWeight(int from, int to, int weight) {
  weights[from * numNodes + to] = weight;
  weights[to * numNodes + from] = weight;
}

void WeightedDenseGraph::addEdge(int from, int to, int weight) {
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

node_helper *ShortestPath(Graph &g, int startV) {

  int numNodes = g.getNumNodes();
  node_helper *nodesH = new node_helper[numNodes];

  nodesH[startV].distance = 0;
  DList unvisitedQueue;
  for (int i = 0; i < numNodes; i++)
    unvisitedQueue.append(i);

  while (!unvisitedQueue.empty()) {
    DList::iterator it = unvisitedQueue.begin();
    int min_node = it.getItem();
    DList::iterator min = it; // remember iterator to minimum
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

    List adjList = g.getAdjacencyList(currentV);
    for (List::iterator lit = adjList.begin(); !lit.end(); lit.increment()) {
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
