#include "../../headers.h"

// BFS

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        queue<vector<int>> q{{{0}}};
        while (!q.empty())
        {
            auto path = move(q.front());
            q.pop();
            if (path.back() == graph.size() - 1)
                ans.push_back(move(path));
            else
                for (auto e : graph[path.back()])
                {
                    path.push_back(e);
                    q.push(path);
                    path.pop_back();
                }
        }
        return ans;
    }
};

// DFS

#define vv vector<vector<int>>
#define vec vector<int>

class Solution
{
    void dfs(vv &g, vv &ans, vec path, int u)
    {
        path.push_back(u);
        for (int v : g[u])
            dfs(g, ans, path, v);
        if (g.size() - 1 == u)
            ans.push_back(path), path.pop_back();
    }

public:
    vv allPathsSourceTarget(vv& g) 
    {
        vv ans;
        vec path;
        dfs(g, ans, path, 0);
        return ans;
    }
};