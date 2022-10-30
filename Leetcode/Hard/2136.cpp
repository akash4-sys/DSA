#include "../../headers.h"

class Solution
{
public:
    int earliestFullBloom(vector<int> &p, vector<int> &g)
    {
        int ans = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < p.size(); i++)
            v.push_back({g[i], p[i]});
        sort(v.begin(), v.end());
        for(auto [gt, pt]: v)
            ans = max(ans, gt) + pt;
        return ans;
    }
};


// @lc app=leetcode id=2136 lang=cpp