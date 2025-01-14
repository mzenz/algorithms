#pragma once

#include <vector>
#include <deque>
#include <list>
#include <limits>
#include <cassert>

class Graph
{
  public:
    Graph(size_t vertices)
      : _adj(vertices)
      , _e(0)
    {
    }

    size_t vertices() const { return _adj.size(); }
    size_t edges() const { return _e; }

    size_t degree(size_t v) const { return _adj.at(v).size(); }

    void addEdge(size_t v, size_t w) {
      assert(v < _adj.size() && w < _adj.size());
      _adj[v].push_back(w);
      _adj[w].push_back(v);
      ++_e;
    }

    const std::list<size_t>& adj(size_t v) const { return _adj[v]; }

  private:
    std::vector<std::list<size_t>> _adj;
    size_t _e;
};

void dfs(
  const Graph& g,
  size_t v,
  std::vector<bool>& visited,
  std::vector<size_t>& edgeTo
) {
  visited[v] = true;
  const auto vertices = g.adj(v);
  for (auto it = vertices.begin(); it != vertices.end(); ++it) {
    size_t w = *it;
    if (!visited[w]) {
      edgeTo[w] = v;
      dfs(g, w, visited, edgeTo);
    }
  }
}

std::list<size_t> findPathDFS(const Graph& g, size_t v, size_t to) {
  std::vector<bool> visited(g.vertices(), false);
  std::vector<size_t> edgeTo(g.vertices());

  dfs(g, v, visited, edgeTo);

  std::list<size_t> path;
  if (visited[to]) {
    for (size_t i = to; i != v; i = edgeTo[i]) {
      path.push_front(i);
    }
    path.push_front(v);
  }

  return path;
}

std::list<size_t> findShortestPath(const Graph& g, size_t from, size_t to) {
  std::vector<bool> visited(g.vertices(), false);
  std::vector<size_t> edgeTo(g.vertices());

  std::deque<size_t> q;
  visited[from] = true;
  q.push_back(from);

  while (!q.empty()) {
    auto v = q.back();
    q.pop_back();

    const auto vertices = g.adj(v);
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
      auto w = *it;
      if ((!visited[w])) {
        edgeTo[w] = v;
        visited[w] = true;
        q.push_back(w);
      }
    }
  }

  std::list<size_t> path;
  if (visited[to]) {
    for (size_t i = to; i != from; i = edgeTo[i]) {
      path.push_front(i);
    }
    path.push_front(from);
  }

  return path;
}
