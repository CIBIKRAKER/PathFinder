//
// Created by girif on 04.09.2026.
//

#ifndef PATHFINDER_GRAPH_H
#define PATHFINDER_GRAPH_H
#include <string>
#include <vector>


class Graph {
private:
    std::vector<std::vector<std::pair<int, double>>> adjacencyList;
public:
    Graph(int size);
    void addEdge(int from, int to, double weight);
    void showEdges();
    std::vector<std::pair<int, double>> getNeighbours(int index);
};


#endif //PATHFINDER_GRAPH_H
