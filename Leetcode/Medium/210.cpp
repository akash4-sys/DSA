#include "../../headers.h"

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        vector<int> indegree(n), ans;
        for (auto e : edges)
            g[e[1]].push_back(e[0]), indegree[e[0]]++;
        
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(!indegree[i])
                q.push(i);
        
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            ans.push_back(v);
            n--;
            for(int c: g[v])
                if(--indegree[c] == 0)
                    q.push(c);
        }

        if(n)
            return {};
        return ans;
    }
};

// @lc app=leetcode id=210 lang=cpp
