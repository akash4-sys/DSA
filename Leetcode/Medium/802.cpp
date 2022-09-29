#include "../../headers.h"

// @lc app=leetcode id=802 lang=cpp

// Time complexity - O(N + E)
// Space complexity - O(N + E)

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &g)
    {
        int n = g.size();
        vector<vector<int>> r(n);
        vector<int> outdegree(n), ans, safe(n);
        queue<int> q;

        for(int i = 0; i < n; i++)
        {
            for(auto c: g[i])
                r[c].push_back(i); 
            outdegree[i] = g[i].size();
            if(!outdegree[i])
                q.push(i);
        }

        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            safe[v] = 1;
            for(auto &c: r[v])
                if(--outdegree[c] == 0)
                    q.push(c);
        }

        for(int i = 0; i < n; i++)
            if(safe[i]) ans.push_back(i);
        return ans;
    }
};


// Classic Gray white DFS
class Solution 
{
    vector<int> col, ans;
    bool dfs(vector<vector<int>>& g, int v)
    {
        if(col[v] > 0)
            return col[v] == 2;
        col[v] = 1;
        for(auto c: g[v])
            if(col[c] == 1 || !dfs(g, c))
                return false;
        
        col[v] = 2;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) 
    {
        int n = g.size();
        col = vector<int>(n, 0);

        for(int i = 0; i < n; i++)
            if(dfs(g, i))
                ans.push_back(i);
        return ans;
    }
};

