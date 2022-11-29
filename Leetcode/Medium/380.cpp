#include "../../headers.h"

class RandomizedSet
{
    unordered_map<int, int> ump;
    vector<int> v;
public:
    RandomizedSet() {}

    bool insert(int n)
    {
        int p = ump.count(n) ? !ump[n] : 1;
        ump[n] = 1;
        v.push_back(n);
        return p;
    }

    bool remove(int n)
    {
        int p = ump.count(n) ? ump[n] : 0;
        ump[n] = 0;
        return p;
    }

    int getRandom()
    {
        while(1)
        {
            int i = rand() % v.size();
            if(ump[v[i]])
                return v[i];
        }
    }
};


// @lc app=leetcode id=380 lang=cpp