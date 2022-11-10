#include "../../headers.h"

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &g)
    {
        queue<tuple<int,int, int>> q;
        vector<vector<int>> vis(g.size(), vector<int>((1 << g.size()), 0));
        for (int i = 0; i < g.size(); i++)
            q.push({i, (1 << i), 1}), vis[i][1 << i] = 1;
        
        while(!q.empty())
        {
            auto [u, mask, d] = q.front();
            q.pop();
            if(mask == (1 << g.size()) - 1)
                return d - 1;
            for(int v: g[u])
            {
                int visPath = mask | (1 << v);
                if(!vis[v][visPath])
                    vis[v][visPath] = 1, q.push({v, visPath, d + 1});
            }
        }
        return -1;
    }
};


class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &g)
    {
        queue<tuple<int,int, int>> q;
        set<pair<int, int>> vis;
        for (int i = 0; i < g.size(); i++)
            q.push({i, (1 << i), 1}), vis.insert({i, (1 << i)});
        
        while(!q.empty())
        {
            auto [u, mask, d] = q.front();
            q.pop();
            if(mask == (1 << g.size()) - 1)
                return d - 1;
            for(int v: g[u])
            {
                int visPath = mask | (1 << v);
                if(vis.find({v, visPath}) == vis.end())
                    vis.insert({v, visPath}), q.push({v, visPath, d + 1});
            }
        }
        return -1;
    }
};