#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    void dfs(vector<int> &v, vector<int> &x, int u, int d = 0)
    {
        // for (int d = 0; u != -1 && x[u] == -1; x[u] = d++, u = v[u]);
        while (u != -1 && x[u] == -1)
            x[u] = d++, u = v[u];
    }

public:
    int closestMeetingNode(vector<int> &e, int u, int v)
    {
        int ans = -1, d = INT_MAX;
        vector<int> x(e.size(), -1), y(e.size(), -1);
        dfs(e, x, u);
        dfs(e, y, v);
        
        for (int i = 0; i < x.size(); i++)
            if (min(x[i], y[i]) != -1 && d > max(x[i], y[i]))
                ans = i, d = max(x[i], y[i]);
        return ans;
    }
};

// @lc app=leetcode id=2359 lang=cpp