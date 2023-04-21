#include "../../headers.h"

// Time Complexity - O(N * M * K)
// Space Complexity - O(N * K)

class Solution
{
public:
    int profitableSchemes(int n, int minPf, vector<int> &v, vector<int> &p)
    {
        int mod = 1e9 + 7, ans = 0;
        vector dp(minPf + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < v.size(); i++)
            for (int j = n - v[i]; j >= 0; j--)
                for (int k = minPf; k >= 0; k--)
                    (dp[min(k + p[i], minPf)][j + v[i]] += dp[k][j]) %= mod;
                    
        for (int pf : dp[minPf])
            (ans += pf) %= mod;
        return ans;
    }
};

// Time Complexity - O(N * M * K)
// Space Complexity - O(N * M * K)

class Solution
{
public:
    int profitableSchemes(int n, int minPf, vector<int> &v, vector<int> &p)
    {
        int mod = 1e9 + 7;
        vector dp(v.size() + 1, vector(n + 1, vector<int>(minPf + 1, 0)));
        for (int j = 0; j <= n; j++)
            dp[v.size()][j][minPf] = 1;
            
        for (int i = v.size() - 1; i >= 0; i--)
            for (int j = 0; j <= n; j++)
                for (int k = 0; k <= minPf; k++)
                {
                    dp[i][j][k] = dp[i + 1][j][k];
                    if (j + v[i] <= n)
                        (dp[i][j][k] += dp[i + 1][j + v[i]][min(k + p[i], minPf)]) %= mod;
                }
        return dp[0][0][0];
    }
};

// Time Complexity - O(N * M * K)
// Space Complexity - O(N * M * K) + stack space

class Solution
{
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int rc(int n, int minPf, vector<int> &v, vector<int> &p, int i, int j, int k)
    {
        if (j > n)
            return 0;
        if (i == v.size())
            return k >= minPf;
        if (dp[i][j][min(k, minPf)] != -1)
            return dp[i][j][min(k, minPf)];
            
        dp[i][j][min(k, minPf)] = rc(n, minPf, v, p, i + 1, j + v[i], k + p[i]);
        return (dp[i][j][min(k, minPf)] += rc(n, minPf, v, p, i + 1, j, k)) %= mod;
    }

public:
    int profitableSchemes(int n, int minPf, vector<int> &v, vector<int> &p)
    {
        dp = vector(v.size(), vector(n + 1, vector<int>(minPf + 1, -1)));
        return rc(n, minPf, v, p, 0, 0, 0);
    }
};

// Time Complexity - O(2^arr.size())
// Space Complexity - O(N)

class Solution
{
    int rc(int n, int k, vector<int> &v, vector<int> &p, int i)
    {
        if (i == v.size())
            return n >= 0 && k <= 0;
        int res = rc(n - v[i], k - p[i], v, p, i + 1);
        return res + rc(n, k, v, p, i + 1);
    }

public:
    int profitableSchemes(int n, int k, vector<int> &v, vector<int> &p)
    {
        return rc(n, k, v, p, 0);
    }
};