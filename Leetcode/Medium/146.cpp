#include "../../headers.h"

class LRUCache
{
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> ump;

public:
    void moveFront(int key)
    {
        auto node = ump[key];
        li.splice(li.begin(), li, node);
        ump[key] = li.begin();
    }

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        if (!ump.count(key))
            return -1;
        moveFront(key);
        return ump[key]->second;
    }

    void put(int key, int value)
    {
        if (ump.count(key))
        {
            moveFront(key);
            ump[key]->second = value;
        }
        else
        {
            li.emplace_front(key, value);
            ump[key] = li.begin();
            if (li.size() > capacity)
            {
                ump.erase(li.rbegin()->first);
                li.pop_back();
            }
        }
    }
};