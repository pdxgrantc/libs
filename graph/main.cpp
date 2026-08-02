#include <iostream>
#include "graph.h"

int main()
{
    // Number of vertices
    int n = 4;
    // Create a graph with 4 vertices
    Graph g(n);

    // Adding the specified edges in the graph
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(2, 1);

    g.print();

    g.add_node();
    g.add_edge(0,4);
    g.add_edge(3,4);

    // Print the adjacency matrix representation of the
    // graph
    g.print();
    return 0;
}