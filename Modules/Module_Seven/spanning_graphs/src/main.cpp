#include "graph.hpp"

#include <print>

static void run_test_case(std::size_t test_index, graph &graph_instance) {
  std::println("\n=== test case {} ===", test_index);

  auto eulerian_trail = graph_instance.find_eulerian_trail();

  if (!eulerian_trail) {
    std::println("no eulerian path exists");
    return;
  }

  for (const auto &[from, to] : *eulerian_trail) {
    std::println("{} -> {}", from, to);
  }
}

int main() {
  // ------------------------------------------------------------
  // test case 1: eulerian circuit
  // ------------------------------------------------------------
  graph graph_case_1(4);
  graph_case_1.add_edge(0, 1);
  graph_case_1.add_edge(1, 2);
  graph_case_1.add_edge(2, 3);
  graph_case_1.add_edge(3, 0);
  graph_case_1.add_edge(0, 2);
  graph_case_1.add_edge(1, 3);

  // ------------------------------------------------------------
  // test case 2: eulerian path
  // ------------------------------------------------------------
  graph graph_case_2(5);
  graph_case_2.add_edge(0, 1);
  graph_case_2.add_edge(1, 2);
  graph_case_2.add_edge(2, 3);
  graph_case_2.add_edge(3, 4);
  graph_case_2.add_edge(1, 3);

  // ------------------------------------------------------------
  // test case 3: non-eulerian graph
  // ------------------------------------------------------------
  graph graph_case_3(4);
  graph_case_3.add_edge(0, 1);
  graph_case_3.add_edge(1, 2);
  graph_case_3.add_edge(2, 3);

  run_test_case(1, graph_case_1);
  run_test_case(2, graph_case_2);
  run_test_case(3, graph_case_3);

  return 0;
}
