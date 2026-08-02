#ifndef GRAPH_TPP
#define GRAPH_TPP

#include <iostream>
#include <vector>

#include "graph.h"

Graph::Graph(int n)
{
    adj_matrix = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
}

void Graph::add_node()
{
    const std::size_t newSize = adj_matrix.size() + 1;

    // Add a zero to the end of every existing row.
    for (auto &row : adj_matrix)
    {
        row.resize(newSize, 0);
    }

    // Add a new row containing only zeros.
    adj_matrix.emplace_back(newSize, 0);
}

void Graph::add_edge(int u, int v)
{
    // Set edge from u to v
    adj_matrix[u][v] = 1;
    // Set edge from v to u (for undirected graph)
    adj_matrix[v][u] = 1;
}

// Function to print the adjacency matrix representation
// of the graph
void Graph::print()
{
    // Get the number of vertices
    std::cout << "Adjacency Matrix for the Graph: " << std::endl;
    int n = adj_matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << adj_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif
