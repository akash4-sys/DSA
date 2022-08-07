#include "../../headers.h"

typedef pair<int, int> p;
class Solution
{
public:
    void convert(vector<vector<int>> points, vector<p> adj[])
    {
        for(int i = 0; i < points.size(); i++)
        {
            
            for(int j = i+1; j < points.size(); j++)
            {

            }
        }
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<p> adj[1000];
        convert(points, adj);
        
        int ans = 0, src = points[0][0], n = points.size();
        vector<int> key(n, INT_MAX);
        vector<bool> vis(n, false);
        priority_queue<p, vector<p>, greater<>> pq;
        pq.push({0, src});
        key[src] = 0;
        while (!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();

            if(vis[node])
                continue;
            
            vis[node] = true;
            
        }
    }
};