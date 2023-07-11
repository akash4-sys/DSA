#include "../../headers.h"

// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

class Solution
{
public:
    int countRoutes(vector<int> &v, int st, int fn, int fuel)
    {
        int mod = 1e9 + 7, n = v.size();
        vector dp(n, vector<int>(fuel + 1, 0));
        for (int f = 0; f <= fuel; f++)
            dp[fn][f] = 1;
        
        for (int f = 0; f <= fuel; f++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i != j && abs(v[i] - v[j]) <= f)
                        (dp[i][f] += dp[j][f - abs(v[i] - v[j])]) %= mod;
        return dp[st][fuel];
    }
};

// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

class Solution
{
    int mod = 1e9 + 7, dp[101][201];
    int dfs(vector<int> &v, int fn, int st, int fuel)
    {
        if (fuel < 0)
            return 0;
        if (dp[st][fuel] != -1)
            return dp[st][fuel];
        
        int res = st == fn;
        for (int i = 0; i < v.size(); i++)
            if (st != i && abs(v[st] - v[i]) <= fuel)
                (res += dfs(v, fn, i, fuel - abs(v[st] - v[i]))) %= mod;
        return dp[st][fuel] = res;
    }

public:
    int countRoutes(vector<int> &v, int st, int fn, int fuel)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(v, fn, st, fuel) % mod;
    }
};