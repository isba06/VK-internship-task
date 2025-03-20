#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>

struct Graph {
    Graph(const std::string & filename);
    Graph(int n_num, int e_num, int d_vertex, std::initializer_list<std::pair<const int, std::vector<int>>> init);
    std::vector<int> distances();
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
private:
    int node_num;
    int edge_num;
    int vertex;
    std::map<int, std::vector<int>> adj_list;
};
