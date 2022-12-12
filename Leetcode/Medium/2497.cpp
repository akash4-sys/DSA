#include "headers.h"

class Solution
{
public:
    int maxStarSum(vector<int> &v, vector<vector<int>> &edges, int k)
    {
        int n = v.size(), ans = INT_MIN;
        vector<priority_queue<int>> g(n);
        for (auto e : edges)
            g[e[1]].push(v[e[0]]), g[e[0]].push(v[e[1]]);

        for(int i = 0; i < n; i++)
        {
            auto &pq = g[i];
            int j = 0, sum = v[i];
            ans = max(ans, sum);
            while(!pq.empty() && j < k)
            {
                sum += pq.top(); 
                pq.pop(); 
                ans = max(ans, sum); 
                j++;
            }
        }        
        return ans;
    }
};