#include "../../headers.h"

class Solution
{
    unordered_map<int, int> mp;
    bool recurse(int n, int t, int vis)
    {
        if (t <= 0)
            return 0;
        if(mp.count(vis))
            return mp[vis];
        for (int i = 0; i < n; i++)
            if (!(vis & (1 << i)) && !recurse(n, t - i - 1, vis | (1 << i)))
                    return mp[vis] = 1;
        return mp[vis] = 0;
    }

public:
    bool canIWin(int n, int t)
    {
        if (t <= n)
            return 1;
        if ((n * (n + 1)) / 2 < t)
            return 0;
        return recurse(n, t, 0);
    }
};



// Time Complexity O(N!)
class Solution
{
    bool recurse(int n, int t, int vis)
    {
        if (t <= 0)
            return 0;
        for (int i = 0; i < n; i++)
            if (!(vis & (1 << i)) && !recurse(n, t - i - 1, vis | (1 << i)))
                    return 1;
        return 0;
    }

public:
    bool canIWin(int n, int t)
    {
        if (t <= n)
            return 1;
        if ((n * (n + 1)) / 2 < t)
            return 0;
        return recurse(n, t, 0);
    }
};


// @lc app=leetcode id=464 lang=cpp