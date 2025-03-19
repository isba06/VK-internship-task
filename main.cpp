#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Graph {
    int node_num = 0;
    int edge_num = 0;
    std::vector<std::pair<int, int>> edges;
};

int main()
{
    Graph graph;
    std::ifstream file("graph.txt");
    if(!file.is_open()){
        std::cout << "file is not exist";
        return 1;
    }

    file >> graph.node_num;
    file >> graph.edge_num;

    int vertex_from = 0;
    int first_edge = 0, second_edge = 0;

    while(file >> first_edge) {
        if(file >> second_edge) {
            graph.edges.push_back({first_edge, second_edge});
        } else {
            vertex_from = first_edge;
        }
    }
    
    return 0;
}