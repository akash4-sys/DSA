#include "../../headers.h"

// Time Complexity - O(V + E)
// Space Complexity - O(V ^ 2)

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int s, int d)
    {
        vector<vector<int>> g(n);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        queue<int> q;
        vector<int> vis(n, 0);
        q.push(s);
        vis[s] = 1;
        while (!q.empty())
        {
            int v = q.front();
            if (d == v)
                return true;
            q.pop();
            for (int vr : g[v])
                if (!vis[vr])
                    q.push(vr), vis[vr] = 1;
        }
        return false;
    }
};



// Union Find

class Solution
{
public:
    int find(vector<int> &g, int i)
    {
        return g[i] < 0 ? i : g[i] = find(g, g[i]);
    }

    bool validPath(int n, vector<vector<int>> &edges, int s, int d)
    {
        vector<int> g(n, -1);
        for(auto e: edges)
        {
            int v1 = find(g, e[0]), v2 = find(g, e[1]);
            if(v1 != v2)
                g[v2] = v1;
        }
        return find(g, s) == find(g, d);
    }
};