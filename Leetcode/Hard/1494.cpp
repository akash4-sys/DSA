#include "../../headers.h"

// Hard to understand how it's working in overall
// Couldn't find good explanation quiting for now.
class Solution
{
public:
    int minNumberOfSemesters(int n, vector<vector<int>> &edges, int k)
    {
        vector<int> masks(n, 0), v(1 << n), dp(1 << n, n + 1);
        dp[0] = 0;
        for(auto &e : edges)
            masks[e[1] - 1] |= (1 << (e[0] - 1));
        
        for(int i = 0; i < (1 << n); i++)
            for(int j = 0; j < n; j++)
                if(i & (1 << j))
                    v[i] |= masks[j];
        
        for(int i = 1; i < (1 << n); i++)
            for(int j = i; j; j = (j - 1) & i)
            {
                int x = i ^ ((1 << n) - 1);
                if(__builtin_popcount(j) <= k && (x & v[j]) == v[j])
                    dp[i] = min(dp[i], dp[i ^ j] + 1);
            }
        return dp.back();
    }
};


// @lc app=leetcode id=1494 lang=cpp