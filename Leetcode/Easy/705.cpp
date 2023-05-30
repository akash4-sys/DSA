#include "../../headers.h"

class MyHashSet
{
    vector<list<int>> hashset;
    int n, cap;
    double loadFactor;

    int hash(int key) {
        return key % cap;
    }

    void rehash()
    {
        n = 0;
        cap = max(2, cap);
        vector<list<int>> oldHashset(move(hashset));
        for (auto arr : oldHashset)
            for (int &key : arr)
                add(key);
    }

public:
    MyHashSet() : n(0), cap(2), loadFactor(0.75), hashset(cap) {}
    
    void add(int key)
    {
        if (contains(key))
            return;
        n++;
        hashset[hash(key)].push_back(key);
        if (n >= loadFactor * cap)
        {
            cap *= 2;
            rehash();
        }
    }
    
    void remove(int key)
    {
        int hashedKey = hash(key);
        auto it = find(hashset[hashedKey].begin(), hashset[hashedKey].end(), key);
        if (it == hashset[hashedKey].end())
            return;
        
        n--;
        hashset[hashedKey].erase(it);
        if (n <= 0.5 * loadFactor * cap) {
            cap /= 2;
            rehash();
        }
    }
    
    bool contains(int key)
    {
        int h = hash(key);
        return find(hashset[h].begin(), hashset[h].end(), key) != hashset[h].end();
    }
};


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