#include <iostream>
#include <string>
#include <vector>

#include "Graph.h"
#include "HashTable.h"
#include "Location.h"

int main() {
    HashTable ht(5000);
    std::vector<Location> locations;   // <-- vector lives here, in main (or wherever you need the list)
    locations.push_back({"Innere Stadt", 48.2082, 16.3738});
    locations.push_back({"Leopoldstadt", 48.2141, 16.3927});
    locations.push_back({"Landstrasse", 48.1966, 16.3908});
    Graph graph(locations.size());



    //Hashing
    for (int i = 0; i < locations.size(); ++i) {
        std::cout << ht.hashFunction(locations[i].name) << std::endl;
    }

    //Inserting the values into the bucket
    for (int i = 0; i < locations.size(); ++i) {
        ht.insert(locations[i].name, i);
    }

    int firstIndex = ht.lookup("Innere Stadt");
    int secondIndex = ht.lookup("Leopoldstadt");
    int thirdIndex = ht.lookup("Landstrasse");

    //Show Buckets
    ht.showBuckets();

    //Find the hashed Data in the bucket
    int idx = ht.lookup("Innere Stadt");
    std::cout << locations[idx].name << " " << locations[idx].latitude << " " << locations[idx].longitude << std::endl;

    //Edging
    graph.addEdge(firstIndex, secondIndex, 3.2);
    graph.addEdge(secondIndex, thirdIndex, 5.3);



    auto neighbours2 = graph.getNeighbours(1);
    for (auto& n : neighbours2) {
        std::cout << n.first << ": " << n.second << std::endl;
    }





    return 0;
}
