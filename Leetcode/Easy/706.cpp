#include "../../headers.h"

class MyHashMap
{
public:
    vector<int> hashMap;
    MyHashMap(): hashMap(1e6 + 1, -1) {}

    void put(int key, int value)
    {
        hashMap[key] = value;
    }

    int get(int key)
    {
        return hashMap[key];
    }

    void remove(int key)
    {
        hashMap[key] = -1;
    }
};