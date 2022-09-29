#include "../../headers.h"

// Classic Topological sort
class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        vector<int> indegree(n);
        for (auto e : edges)
            g[e[1]].push_back(e[0]), indegree[e[0]]++;

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!indegree[i])
                q.push(i);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            n--;
            for (auto c : g[v])
                if (--indegree[c] == 0)
                    q.push(c);
        }
        return n == 0;
    }
};



// Another way to write topological sort
class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        vector<int> indegree(n), q;
        for (auto e : edges)
            g[e[1]].push_back(e[0]), indegree[e[0]]++;

        for (int i = 0; i < n; i++)
            if (!indegree[i])
                q.push_back(i);
        
        for(int i = 0; i < q.size(); i++)
            for(int c: g[q[i]])
                if (--indegree[c] == 0)
                    q.push_back(c);

        return q.size() == n;
    }
};

// @lc app=leetcode id=207 lang=cpp