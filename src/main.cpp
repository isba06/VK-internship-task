#include "graph.h"

int main()
{
    Graph graph("graph.txt");

    auto dist = graph.distances();

    for(const auto & d : dist) {
        std::cout << d << '\n';
    }
    
    return 0;
}