#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>

struct Graph {
    int node_num = 0;
    int edge_num = 0;
    std::map<int, std::vector<int>> adj_list;
    Graph(const std::string & filename);
};

std::ostream& operator<<(std::ostream& os, const Graph& graph)
{
    os << "node num: " << graph.node_num << ", edge num: " << graph.edge_num << '\n';
    os << "   Vertex FROM\t  " << "Verteces TO\n";
    for(const auto & [vertex, verteces_list] : graph.adj_list) {
        os << '\t' << vertex << "\t     ";
        for(const auto & vertex2 : verteces_list) {
            os << vertex2 << ' ';
        }
        os << '\n';
    }
    return os;
}

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
            graph.adj_list[first_edge].push_back(second_edge);
            graph.adj_list[second_edge].push_back(first_edge);
        } else {
            vertex_from = first_edge;
        }
    }
    file.close();

    std::queue<int> q;
    std::vector<int> dist(graph.node_num, INT_MAX);
    dist[vertex_from] = 0;
    q.push(vertex_from);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (const auto & u : graph.adj_list[v]) {
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    for(const auto & d : dist) {
        std::cout << d << '\n';
    }
    return 0;
}