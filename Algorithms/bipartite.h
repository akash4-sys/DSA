#pragma once

#include <vector>
#include <queue>

using namespace std;

class Bipartite
{
public:
    bool check(vector<vector<int>> &g, int n)
    {
        vector<int> colors(n, 0);
        queue<int> q;
        for(int i = 0; i < n; i++)
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