#include "../../headers.h"
// @lc app=leetcode id=851 lang=cpp

// Topolgical Sort Not pure though
// Time complexity O(V + E) = O(N)
// Space Complexity O(N)

class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &edges, vector<int> &qu)
    {
        int n = qu.size();
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0), ans(n);
        for (auto e : edges)
            indegree[e[1]]++, g[e[0]].push_back(e[1]);

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            ans[i] = i;
            if (!indegree[i])
                q.push(i);
        }

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto &c : g[v])
            {
                if (qu[ans[c]] > qu[ans[v]])
                    ans[c] = ans[v];
                if (--indegree[c] == 0)
                    q.push(c);
            }
        }
        return ans;
    }
};

// Cached Dfs

class Solution
{
    unordered_map<int, vector<int>> ump;
    vector<int> ans;
    int dfs(int i, vector<int> &q)
    {
        if(ans[i] >= 0)
            return ans[i];
        ans[i] = i;
        for(int j: ump[i])
            if(q[ans[i]] > q[dfs(j, q)])
                ans[i] = ans[j];
        return ans[i];
    }

public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &q)
    {
        for(auto v: richer)
            ump[v[1]].push_back(v[0]);
        ans = vector<int>(q.size(), -1);
        for(int i = 0; i < q.size(); i++)
            dfs(i, q);
        return ans;
    }
};


