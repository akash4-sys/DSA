#include "../../headers.h"

class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {
        unordered_map<long long, long long> umap;
        for (int i = 0; i < edges.size(); i++)
            umap[edges[i]] += i;
        
        long long maxi = INT_MIN, ans = 0;
        for (auto x: umap)
        {
            if(x.second > maxi)
            {
                maxi = x.second;
                ans = x.first;
            }
            else if(x.second == maxi)
                ans = min(x.first, ans);
        }
        return ans;
    }
};