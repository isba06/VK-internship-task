#include <gtest/gtest.h>
#include "graph.h"


TEST(GraphTest, Empty) {
  Graph graph(0, 0, 0, {});
  EXPECT_EQ(graph.distances().size(), 0);
}

TEST(GraphTest, VertexNotExist) {
  Graph graph(2, 1, 4, {{0, {0, 1}}, {1, {0}}});
  EXPECT_EQ(graph.distances().size(), 0);
}

TEST(GraphTest, Example0) {
  Graph graph(5, 4, 4, {{0, {1, 4}}, 
                         {1, {0, 2, 3}}, 
                         {2, {0, 1}}, 
                         {3, {1}}, 
                         {4, {0}}});

  std::vector<int> expected = {1, 2, 3, 3, 0};

  auto dist = graph.distances();

  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}