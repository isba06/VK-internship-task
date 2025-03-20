#include <gtest/gtest.h>
#include "graph.h"


TEST(GraphTest, Example0) {
  Graph graph(5, 4, 4, {{0, {1, 4}}, 
                         {1, {0, 2, 3}}, 
                         {2, {1}}, 
                         {3, {1}}, 
                         {4, {0}}});

  std::vector<int> expected = {1, 2, 3, 3, 0};

  auto dist = graph.distances();

  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}

TEST(GraphTest, Example1) {
  Graph graph(5, 4, 4, {{0, {1, 4}}, 
                         {1, {0, 2, 3}}, 
                         {2, {1}}, 
                         {3, {1}}, 
                         {4, {0}}});

  std::vector<int> expected = {2, 1, 2, 0, 3};

  auto dist = graph.distances(3);

  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}

TEST(GraphTest, Example2) {
  Graph graph(5, 4, 4, {{0, {1, 4}}, 
                         {1, {0, 2, 3}}, 
                         {2, {1}}, 
                         {3, {1}}, 
                         {4, {0}}});

  std::vector<int> expected = {1, 0, 1, 1, 2};

  auto dist = graph.distances(1);

  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}

TEST(GraphTest, Example3) {
  Graph graph(5, 4, 4, {{0, {1, 4}}, 
                         {1, {0, 2, 3}}, 
                         {2, {1}}, 
                         {3, {1}}, 
                         {4, {0}}});

  std::vector<int> expected = {0, 1, 2, 2, 1};

  auto dist = graph.distances(0);

  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}

TEST(GraphTest, Example4) {
  Graph graph(5, 4, 4, {{0, {1, 4}}, 
                         {1, {0, 2, 3}}, 
                         {2, {1}}, 
                         {3, {1}}, 
                         {4, {0}}});

  std::vector<int> expected = {2, 1, 0, 2, 3};

  auto dist = graph.distances(2);

  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}

TEST(GraphTest, Empty) {
  Graph graph(0, 0, 0, {});
  EXPECT_EQ(graph.distances().size(), 0);
}

TEST(GraphTest, VertexNotExist) {
  Graph graph(2, 1, 4, {{0, {0, 1}}, {1, {0}}});
  EXPECT_EQ(graph.distances().size(), 0);
}

TEST(GraphTest, SingleVertex) {
  Graph graph(1, 0, 0, {{0, {}}});
  std::vector<int> expected = {0};
  auto dist = graph.distances(0);
  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}

TEST(GraphTest, DisconnectedGraph) {
  Graph graph(3, 2, 0, {{0, {1}}, {1, {0}}, {2, {}}});
  std::vector<int> expected = {0, 1, INT_MAX};
  auto dist = graph.distances(0);
  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}

TEST(GraphTest, CycleGraph) {
  Graph graph(4, 4, 0, {{0, {1, 3}}, {1, {0, 2}}, {2, {1, 3}}, {3, {0, 2}}});
  std::vector<int> expected = {0, 1, 2, 1};
  auto dist = graph.distances(0);
  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}

TEST(GraphTest, LargeGraph) {
  Graph graph(10, 9, 0, {{0, {1}}, {1, {2}}, {2, {3}}, {3, {4}}, {4, {5}}, {5, {6}}, {6, {7}}, {7, {8}}, {8, {9}}});
  std::vector<int> expected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto dist = graph.distances(0);
  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}

TEST(GraphTest, FullyConnectedGraph) {
  Graph graph(4, 6, 0, {{0, {1, 2, 3}}, {1, {0, 2, 3}}, {2, {0, 1, 3}}, {3, {0, 1, 2}}});
  std::vector<int> expected = {0, 1, 1, 1};
  auto dist = graph.distances(0);
  ASSERT_EQ(expected.size(), dist.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_EQ(expected[i], dist[i]);
  }
}
