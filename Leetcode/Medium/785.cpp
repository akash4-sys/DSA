#include "../../headers.h"

// @ bipartite graph
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &g)
    {
        vector<int> colors(g.size(), 0);
        queue<int> q;
        for(int i = 0; i < g.size(); i++)
        {
            if(colors[i])
                continue;
            colors[i] = 1;
            q.push(i);
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(int v: g[u])
                {
                    if(!colors[v])
                        colors[v] = -colors[u], q.push(v);
                    if(colors[v] == colors[u])
                        return false;
                }
            }
        }
        return 1;
    }
};


// @ Missing Something
class Solution
{
    bool dfs(vector<vector<int>> &g, vector<int> &colors, int u, int color)
    {
        colors[u] = color;
        for(int v: g[u])
        {
            if(colors[v] == -color)
                continue;
            if(colors[v] == color || !dfs(g, colors, v, -color))
                return 0;
        }
        return 1;
    }

public:
    bool isBipartite(vector<vector<int>> &g)
    {
        vector<int> colors(g.size());
        for(int i = 0; i < g.size(); i++)
            if(colors[i] == 0 && !dfs(g, colors, i, 1));
                return 0;
        return 1;
    }
};