#include "../../headers.h"

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &v, int k, int n)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < v.size(); i++)
        {
            int key = v[i] / (n + 1);
            key -= v[i] < 0;
            if (mp.count(key) && mp[key] != INT_MAX)
                return true;
            mp[key] = v[i];
            if ((mp.count(key - 1) && mp[key - 1] != INT_MAX && (v[i] - mp[key - 1]) <= n) 
                || (mp.count(key + 1) && mp[key + 1] != INT_MAX && (mp[key + 1] - v[i]) <= n))
                return true;
            if (i - k >= 0)
            {
                int x = v[i - k] / (n + 1);
                x -= v[i - k] < 0;
                mp[x] = INT_MAX;
            }
        }
        return false;
    }
};

// @lc app=leetcode id=220 lang=cpp