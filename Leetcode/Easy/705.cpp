#include "../../headers.h"

class MyHashSet {
public:
    
    vector<int> keyContainer;
    MyHashSet() : keyContainer(1e6 + 1, 0) {}
    
    void add(int key) {
        keyContainer[key] = 1;
    }
    
    void remove(int key) {
        keyContainer[key] = 0;
    }
    
    bool contains(int key) {
        return keyContainer[key];
    }
};