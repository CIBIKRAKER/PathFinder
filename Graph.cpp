//
// Created by girif on 04.09.2026.
//

#include "Graph.h"

#include <iostream>

Graph::Graph(int size) {
        adjacencyList.resize(size);
}

//Connects neighbor districts
void Graph::addEdge(int from, int to, double weight) {
        adjacencyList[from].push_back({to, weight});
        adjacencyList[to].push_back({from, weight});
}

void Graph::showEdges() {
        for (int i = 0; i < adjacencyList.size(); ++i) {
                for (auto& entry : adjacencyList[i]) {
                        std::cout << entry.first << ": ";
                        std::cout << entry.second << std::endl;
                }
        }

}

std::vector<std::pair<int, double>> Graph::getNeighbours(int index) {
        return adjacencyList[index];
}


