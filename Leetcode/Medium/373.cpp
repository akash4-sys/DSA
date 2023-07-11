#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &a, vector<int> &b, int k)
    {
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        map<pair<int, int>, int> vis;
        pq.push({a[0] + b[0], 0, 0});
        vis[{0, 0}] = 1;

        while(!pq.empty() && k--)
        {
            auto v = pq.top();
            pq.pop();
            int i = v[1], j = v[2];
            ans.push_back({a[i], b[j]});
            if (i + 1 < a.size() && !vis.count({i + 1, j}))
                pq.push({a[i + 1] + b[j], i + 1, j}), vis[{i + 1, j}] = 1;
            if (j + 1 < b.size() && !vis.count({i, j + 1}))
                pq.push({a[i] + b[j + 1], i, j + 1}), vis[{i, j + 1}] = 1;
        }
        return ans;
    }
};