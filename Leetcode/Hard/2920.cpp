#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    int k, dp[100001];
    vector<vector<int>> g;

    int rec(vector<int> &c, int u, int d, int par)
    {
        if (d > 10000 || dp[u] & d)
            return 0;
        
        dp[u] |= d;
        int op1 = (c[u] / d) - k, op2 = c[u] / (d * 2);
        for (int v : g[u])
            if (v != par)
                op1 += rec(c, v, d, u), op2 += rec(c, v, d * 2, u);
        return max(op1, op2);
    }

public:
    int maximumPoints(vector<vector<int>> &edges, vector<int> &c, int k)
    {
        this->k = k;
        g = vector<vector<int>>(c.size());
        for (auto e : edges) {
            g[e[1]].push_back(e[0]);
            g[e[0]].push_back(e[1]);
        }
        return rec(c, 0, 1, -1);
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    int k, dp[100001][14];
    vector<vector<int>> g;

    int rec(vector<int> &c, int u, int d, int par)
    {
        if (d > 13)
            return 0;
        if (dp[u][d] != -1)
            return dp[u][d];

        int op1 = (c[u] >> d) - k, op2 = c[u] >> (d + 1);
        for (int v : g[u])
            if (v != par)
                op1 += rec(c, v, d, u), op2 += rec(c, v, d + 1, u);
        return dp[u][d] = max(op1, op2);
    }

public:
    int maximumPoints(vector<vector<int>> &edges, vector<int> &c, int k)
    {
        this->k = k;
        g = vector<vector<int>>(c.size());
        memset(dp, -1, sizeof(dp));
        for (auto e : edges) {
            g[e[1]].push_back(e[0]);
            g[e[0]].push_back(e[1]);
        }
        return rec(c, 0, 0, -1);
    }
};