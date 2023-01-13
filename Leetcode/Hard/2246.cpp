#include "../../headers.h"

class Solution
{
    int ans = 0;
    int dfs(vector<vector<int>> &g, string &s, int u)
    {
        int currD = 0, maxD = 0;
        for (int v : g[u])
        {
            int x = dfs(g, s, v);
            if (s[u] == s[v])
                continue;
            maxD = max(maxD, x);
            if (maxD > currD)
                swap(currD, maxD);
        }
        ans = max(ans, currD + maxD + 1);
        return currD + 1;
    }

public:
    int longestPath(vector<int> &par, string s)
    {
        vector<vector<int>> g(s.size());
        for (int i = 1; i < s.size(); i++)
            g[par[i]].push_back(i);
        dfs(g, s, 0);
        return ans;
    }
};

// @lc app=leetcode id=2246 lang=cpp