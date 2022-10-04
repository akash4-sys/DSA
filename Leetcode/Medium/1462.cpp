#include "../../headers.h"

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &edges, vector<vector<int>> &qr)
    {
        vector<bool> ans;
        vector<vector<int>> g(n), grid(n, vector<int>(n, 0));
        vector<int> indegree(n, 0);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), indegree[e[1]]++;

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!indegree[i])
                q.push(i);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for(auto c: g[v])
            {
                grid[v][c] = 1;
                for(int i = 0; i < n; i++)
                    if(grid[i][v])
                        grid[i][c] = 1;
                if(--indegree[c] == 0)
                    q.push(c);
            }
        }

        for(int i = 0; i < qr.size(); i++)
            ans.push_back(grid[qr[i][0]][qr[i][1]]);
        return ans;
    }
};


// @lc app=leetcode id=1462 lang=cpp