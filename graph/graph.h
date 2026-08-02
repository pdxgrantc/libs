#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{
    std::vector<std::vector<int>> adj_matrix;

public:
    Graph(int n);
    void add_edge(int u, int v);
    void print();
    void add_node();
};

#include "graph.tpp"

#endif
