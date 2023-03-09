#include "../../headers.h"

class Solution
{
public:
    int countWays(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        int ans = 1, mod = 1e9 + 7, r = -1;
        for (auto &a : v)
        {
            if (r < a[0])
                ans = (ans * 2) % mod;
            r = max(r, a[1]);
        }
        return ans;
    }
};


// @lc app=leetcode id=2580 lang=cpp