#include "../../headers.h"

class Solution
{
    int dp[16384] = {[0 ... 16383] = INT_MAX}; // LIKE MEMSET
public:
    int minimumXORSum(vector<int> &x, vector<int> &y, int  i = 0, int mask = 0)
    {
        if (i == x.size())
            return 0;
        if(dp[mask] == INT_MAX)
            for(int j = 0; j < x.size(); j++)
                if(!(mask & (1 << j)))
                    dp[mask] = min(minimumXORSum(x, y, i + 1, mask + (1 << j)) + (x[i] ^ y[j]), dp[mask]);
        return dp[mask];
    }
};

//  @lc app=leetcode id=1879 lang=cpp