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
