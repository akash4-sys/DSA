#include "../../headers.h"

// concise version

typedef pair<int, int> p;
typedef tuple<int, int, int> t;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &edges, int src, int dest, int k)
    {
        vector<vector<p>> g(n);
        priority_queue<t, vector<t>, greater<t>> pq;
        vector<int> vis(n, INT_MAX);

        for (auto e : edges)
            g[e[0]].push_back({e[1], e[2]});
        pq.push({0, 0, src});
        k++;

        while (!pq.empty())
        {
            auto [w, stops, v] = pq.top();
            pq.pop();
            vis[v] = stops;
            if (v == dest)
                return w;
            for (auto [c, cw] : g[v])
                if (stops + 1 <= vis[c] && stops + 1 <= k)
                    pq.push({w + cw, stops + 1, c});
        }
        return -1;
    }
};


typedef pair<int, int> p;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &edges, int src, int dest, int k)
    {
        vector<vector<p>> g(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> vis(n, INT_MAX);

        for (auto e : edges)
            g[e[0]].push_back({e[1], e[2]});
        pq.push({0, 0, src});
        k++;

        while (!pq.empty())
        {
            auto pqt = pq.top();
            int w = pqt[0], stops = pqt[1], v = pqt[2];
            pq.pop();
            if(stops > vis[v])
                continue;
            vis[v] = stops;
            if (v == dest)
                return w;
            for (auto [c, cw] : g[v])
                if (stops + 1 <= k)
                    pq.push({w + cw, stops + 1, c});
        }
        return -1;
    }
};