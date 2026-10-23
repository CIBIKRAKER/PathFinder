//
// Created by girif on 14.08.2026.
//

#ifndef PATHFINDER_HASHTABLE_H
#define PATHFINDER_HASHTABLE_H
#include <string>
#include <vector>


class HashTable {

private:
    std::vector<std::vector<std::pair<std::string, int>>> buckets;
    int capacity;

public:
    HashTable(int capacity);
    unsigned long hashFunction(const std::string& location);
    void insert(const std::string& location, int value);
    int lookup(const std::string& location);
    void showBuckets();
};


#endif //PATHFINDER_HASHTABLE_H
