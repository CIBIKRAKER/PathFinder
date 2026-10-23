//
// Created by girif on 14.08.2026.
//
#include <iostream>
#include "HashTable.h"

HashTable::HashTable(int capacity) {
    this->capacity = capacity;
    buckets.resize(capacity);
}

unsigned long HashTable::hashFunction(const std::string& location) {
    unsigned long hash = 0;
    unsigned long prime = 31;
    for (char c : location) {
        hash = hash * prime + c;
    }
    return hash % this->capacity;
}


//Inserts the data into the hashtable
void HashTable::insert(const std::string& location, int value) {
    unsigned long hash = hashFunction(location);
    buckets[hash].push_back({location, value});

}

//Finds the index and returns it
int HashTable::lookup(const std::string& location) {
    unsigned long hash = hashFunction(location);
    auto bucket = buckets[hash];

    for (int i = 0; i < bucket.size(); i++) {
        if (bucket[i].first == location) {
            return bucket[i].second;
        }
    }
    return -1;
}


//Shows the whole list of Buckets
void HashTable::showBuckets() {
    for (int i = 0; i < capacity; ++i) {
        if (!buckets[i].empty()) {
            std::cout << "Bucket " << i << ": ";
            for (auto& entry : buckets[i]) {
                std::cout << "(" << entry.first << ", " << entry.second << ") ";
            }
            std::cout << std::endl;
        }
    }
}
