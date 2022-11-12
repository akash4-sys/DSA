#include "headers.h"

class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, 0);
        int mod = 1e9 + 7, ans = 0;
        dp[0] = 1;
        for(int i = 1; i <= high; i++)
        {
            if(i >= zero) dp[i] = (dp[i] + dp[i - zero]) % mod;
            if(i >= one) dp[i] = (dp[i] + dp[i - one]) % mod;
            if(i >= low) ans = (dp[i] + ans) % mod;
        }
        return ans;
    }
};


class Solution
{
    int mod = 1e9 + 7, z, o;
    int recurse(vector<int> &dp, int t)
    {
        if(t == 0)
            return 1;
        if(t < 0)
            return 0;
        if(dp[t] != -1)
            return dp[t];
        return dp[t] = (recurse(dp, t - o) + recurse(dp, t - z)) % mod;
    }
    
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        z = zero, o = one;
        vector<int> dp(high + 1, -1);
        int ans = 0;
        while(low <= high)
            ans = (ans + recurse(dp, low)) % mod;
        return ans;
    }
};