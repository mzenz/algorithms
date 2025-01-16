#include <iostream>
#include "Graph.h"

using namespace std;

void printGraph(const Graph& g) {
  for (size_t v = 0; v < g.vertices(); ++v) {
    cout << v << " | ";
    const auto vertices = g.adj(v);
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
      cout << *it << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(int argc, const char * argv[])
{
  Graph g(6);

  g.addEdge(0,2);
  g.addEdge(0,1);
  g.addEdge(0,5);
  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(2,4);
  g.addEdge(3,5);
  g.addEdge(3,4);

  // cout << "graph vertices: " << g.vertices() << endl;
  // cout << "graph edges: " << g.edges() << endl;
  // printGraph(g);

  const size_t from = 0, to = 5;
  // const size_t from = 0, to = 3;
  // const size_t from = 0, to = 4;
  // const size_t from = 0, to = 1;

  cout << "Traversing graph from " << from << " -> " << to << ":" << endl;

  auto path = findPath(g, from, to);

  cout << "Depth-first path:" << endl;
  for (auto i : path) {
    cout << i << " ";
  }
  cout << endl;
  cout << "path size: " << path.size() - 1 << endl;

  auto shortestPath = findShortestPath(g, from, to);
  cout << "Shortest path:" << endl;
  for (auto i : shortestPath) {
    cout << i << " ";
  }
  cout << endl;
  cout << "path size: " << shortestPath.size() - 1 << endl;
}
