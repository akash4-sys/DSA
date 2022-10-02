#include "../../headers.h"

class Solution
{
public:
    int numRollsToTarget(int n, int l, int t)
    {
        vector<int> v(t + 1, 0);
        int j, mod = 1e9 + 7;
        v[0] = 1;
        for(int i = 1; i <= n; i++)
            for(int k = t; k >= (i == n ? t : 0); --k)
                for(j = k - 1, v[k] = 0; j >= max(0, k - l); --j)
                    v[k] = (v[k] + v[j]) % mod;
        return v[t];
    }
};

// @lc app=leetcode id=1155 lang=cpp