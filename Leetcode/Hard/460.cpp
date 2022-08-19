#include "../../headers.h"

class LFUCache
{
    int capacity = 0, minFreq = 0;
    unordered_map<int, pair<int, int>> cache;
    unordered_map<int, list<int>::iterator> liItrMap;
    unordered_map<int, list<int>> freqMap;

    void updateFrequency(int key)
    {
        int freq = cache[key].second++;
        freqMap[freq].erase(liItrMap[key]);
        freqMap[freq + 1].push_front(key);
        liItrMap[key] = freqMap[freq + 1].begin();

        if (freqMap[minFreq].size() == 0)
            freqMap.erase(minFreq++);
    }

public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        if (!cache.count(key))
            return -1;

        updateFrequency(key);
        return cache[key].first;
    }

    void put(int key, int value)
    {
        if (capacity <= 0)
            return;

        if (cache.count(key))
        {
            updateFrequency(key);
            cache[key].first = value;
        }
        else
        {
            if (cache.size() >= capacity)
            {
                int LFKey = freqMap[minFreq].back();
                cache.erase(LFKey);
                liItrMap.erase(LFKey);
                freqMap[minFreq].pop_back();
            }
            cache[key] = {value, 0};
            freqMap[0].push_front(key);
            liItrMap[key] = freqMap[0].begin();
            minFreq = 0;
        }
    }
};