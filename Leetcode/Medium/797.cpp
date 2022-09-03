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

class Solution
{
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<vector<int>> &graph, int i)
    {
        path.push_back(i);
        if(i == graph.size() - 1)
            ans.push_back(path);
        else
            for(auto e: graph[i])
                dfs(graph, e);
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        dfs(graph, 0);
        return ans;
    }
};