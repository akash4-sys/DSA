#include "../../headers.h"

// Prim's algorithm
// Not Pure
// Time complexity O(E * log(V))
// Space complexity O(N)

typedef pair<int, int> p;
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &e)
    {
        int ans = 0, connected = 0, i = 0, n = e.size();
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> vis(n, 0);

        while (++connected < n)
        {
            vis[i] = 1;
            for (int j = 0; j < n; ++j)
                if (!vis[j])
                    pq.push({(abs(e[i][1] - e[j][1]) + abs(e[i][0] - e[j][0])), j});

            while (vis[pq.top().second])
                pq.pop();
            ans += pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};




// Kruksal's Algorithm
// Time complexity - O(K * log(N ^ 2))
// Space complexity - O(N^2)

// In kruksal's algorithm sorting is done according to weight but that's not accepted solution here as time
// complexity is high

class DSU
{
    vector<int> par;
    int sz;
public:
    DSU(int n) : par(n)
    {
        iota(par.begin(), par.end(), 0);
    }

    int find(int x)
    {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    void Union(int x, int y)
    {
        auto xp = find(x), yp = find(y);
        if(xp == yp)
            return;
        par[xp] = yp;
        --sz;
    }
};

typedef tuple<int, int, int> t;
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &e)
    {
        int n = e.size(), ans = 0;
        priority_queue<t, vector<t>, greater<t>> pq;

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                pq.push({abs(e[i][0] - e[j][0]) + abs(e[i][1] - e[j][1]), i, j});
        
        DSU uf(n);
        while(!pq.empty())
        {
            auto [w, u, v] = pq.top();
            pq.pop();
            if(uf.find(u) == uf.find(v))
                continue;
            uf.Union(u, v);
            ans += w;
        }
        return ans;
    }
};

// @lc app=leetcode id=1584 lang=cpp