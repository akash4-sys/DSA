#include "../../headers.h"

class Solution
{
public:
    int maximumANDSum(vector<int> &v, int x)
    {
        int n = x * 2;
        v.resize(n);
        vector<int> dp(1 << n);
        for(int i = 1; i < (1 << n); i++)
        {
            int slots = (__builtin_popcount(i) + 1) / 2;
            for(int j = 0; j < n; j++)
                if(i & (1 << j))
                    dp[i] = max(dp[i], dp[i ^ (1 << j)] + (v[j] & slots));
        }
        return dp.back();
    }
};