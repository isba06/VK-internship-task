#include "graph.h"

Graph::Graph(int n_num, int e_num, int d_vertex, std::initializer_list<std::pair<const int, std::vector<int>>> init) 
            : node_num(n_num), edge_num(e_num), vertex(d_vertex), adj_list(init) 
{
}

Graph::Graph(const std::string & filename)
{
    std::ifstream file("graph.txt");
    if(!file.is_open()){
        throw std::runtime_error("Error: file is not exist: " + filename);;
    }

    file >> node_num;
    file >> edge_num;

    int first_edge = 0, second_edge = 0;

    while(file >> first_edge) {
        if(file >> second_edge) {
            adj_list[first_edge].push_back(second_edge);
            adj_list[second_edge].push_back(first_edge);
        } else {
            vertex = first_edge;
        }
    }
    file.close();
}

std::vector<int> Graph::distances()
{
    if(!adj_list.contains(vertex)) {
        return {};
    }
    
    std::queue<int> q;
    std::vector<int> dist(node_num, INT_MAX);
    dist[vertex] = 0;
    q.push(vertex);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (const auto & u : adj_list[v]) {
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    return dist;
}

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