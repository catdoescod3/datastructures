#include "graph.hpp"

#include <algorithm>
#include <ranges>
#include <vector>

graph::graph(std::size_t vertex_count)
    : vertex_count_(vertex_count), adjacency_list_(vertex_count) {}

void graph::add_edge(vertex from, vertex to) {
  if (from >= vertex_count_ || to >= vertex_count_) {
    return;
  }

  adjacency_list_[from].push_back(to);
  adjacency_list_[to].push_back(from);
}

bool graph::has_eulerian_candidate() const {
  std::size_t odd_degree_count = 0;

  for (const auto &neighbors : adjacency_list_) {
    if ((neighbors.size() % 2) != 0) {
      ++odd_degree_count;
    }
  }

  return odd_degree_count == 0 || odd_degree_count == 2;
}

void graph::remove_edge(std::vector<std::list<vertex>> &adjacency_list,
                        vertex from, vertex to) const {
  adjacency_list[from].remove(to);
  adjacency_list[to].remove(from);
}

std::size_t graph::reachable_vertex_count(
    vertex start_vertex,
    const std::vector<std::list<vertex>> &adjacency_list) const {
  std::vector<bool> visited(vertex_count_, false);
  std::vector<vertex> stack;

  visited[start_vertex] = true;
  stack.push_back(start_vertex);

  while (!stack.empty()) {
    vertex current_vertex = stack.back();
    stack.pop_back();

    for (vertex adjacent_vertex : adjacency_list[current_vertex]) {
      if (!visited[adjacent_vertex]) {
        visited[adjacent_vertex] = true;
        stack.push_back(adjacent_vertex);
      }
    }
  }

  return std::ranges::count(visited, true);
}

bool graph::is_bridge(vertex from, vertex to,
                      std::vector<std::list<vertex>> &adjacency_list) const {
  // If this is the only available edge, it must be taken
  if (adjacency_list[from].size() == 1) {
    return false;
  }

  std::size_t reachable_before = reachable_vertex_count(from, adjacency_list);

  remove_edge(adjacency_list, from, to);

  std::size_t reachable_after = reachable_vertex_count(from, adjacency_list);

  // Restore edge
  adjacency_list[from].push_back(to);
  adjacency_list[to].push_back(from);

  return reachable_after < reachable_before;
}

std::optional<std::vector<graph::edge>> graph::find_eulerian_trail() const {
  if (!has_eulerian_candidate()) {
    return std::nullopt;
  }

  std::vector<std::list<vertex>> adjacency_list = adjacency_list_;

  vertex start_vertex = 0;
  for (vertex v = 0; v < vertex_count_; ++v) {
    if ((adjacency_list_[v].size() % 2) != 0) {
      start_vertex = v;
      break;
    }
  }

  std::vector<edge> eulerian_path;
  vertex current_vertex = start_vertex;

  while (!adjacency_list[current_vertex].empty()) {
    bool edge_chosen = false;

    for (vertex next_vertex : adjacency_list[current_vertex]) {
      if (!is_bridge(current_vertex, next_vertex, adjacency_list)) {
        remove_edge(adjacency_list, current_vertex, next_vertex);
        eulerian_path.emplace_back(current_vertex, next_vertex);
        current_vertex = next_vertex;
        edge_chosen = true;
        break;
      }
    }

    if (!edge_chosen) {
      vertex next_vertex = adjacency_list[current_vertex].front();
      remove_edge(adjacency_list, current_vertex, next_vertex);
      eulerian_path.emplace_back(current_vertex, next_vertex);
      current_vertex = next_vertex;
    }
  }

  return eulerian_path;
}
