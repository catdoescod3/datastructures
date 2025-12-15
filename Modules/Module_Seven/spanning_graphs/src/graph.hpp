#ifndef H_GRAPH
#define H_GRAPH

#include <cstddef>
#include <list>
#include <optional>
#include <utility>
#include <vector>

class graph {
public:
  using vertex = std::size_t;
  using edge = std::pair<vertex, vertex>;

  explicit graph(std::size_t vertex_count);

  void add_edge(vertex from, vertex to);

  std::optional<std::vector<edge>> find_eulerian_trail() const;

private:
  std::size_t vertex_count_;
  std::vector<std::list<vertex>> adjacency_list_;

  bool has_eulerian_candidate() const;

  bool is_bridge(vertex from, vertex to,
                 std::vector<std::list<vertex>> &adjacency_list) const;

  void remove_edge(std::vector<std::list<vertex>> &adjacency_list, vertex from,
                   vertex to) const;

  std::size_t reachable_vertex_count(
      vertex start_vertex,
      const std::vector<std::list<vertex>> &adjacency_list) const;
};

#endif
