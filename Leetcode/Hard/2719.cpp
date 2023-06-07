#include "../../headers.h"

class Solution
{
    int dp[23][403][2] = {0}, mod = 1e9 + 7;
    long long rec(string &s, int minS, int maxS, int i, int sum, bool tight)
    {
        if (i == s.size())
            return sum >= minS && sum <= maxS;
        if (dp[i][sum][tight] != -1)
            return dp[i][sum][tight];
        
        long long ans = 0;
        for (int j = 0; j <= (tight ? (s[i] - '0') : 9); j++)
        {
            bool t = tight ? (s[i] - '0') == j : 0;
            (ans += rec(s, minS, maxS, i + 1, sum + j, t)) %= mod;
        }
        return dp[i][sum][tight] = ans;
    }

public:
    int count(string s, string r, int minS, int maxS)
    {
        memset(dp, -1, sizeof(dp));
        long h = rec(r, minS, maxS, 0, 0, 1);
        memset(dp, -1, sizeof(dp));
        long l = rec(s, minS, maxS, 0, 0, 1), sum = 0;

        for (auto ch : s)
            sum += (ch - '0');
        l -= (sum >= minS && sum <= maxS);
        return ((h - l) + mod) % mod;
    }
};