#include "../../headers.h"

class Solution
{
public:
    int maximumBags(vector<int> &cap, vector<int> &r, int k)
    {
        vector<vector<int>> v(r.size());
        for (int i = 0; i < r.size(); i++)
            v[i] = {cap[i], r[i]};

        sort(v.begin(), v.end(), [&](const auto &a, const auto &b){
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int ans = 0;
        for (auto &bag: v)
        {
            if (k && bag[0] - bag[1] <= k)
                k -= (bag[0] - bag[1]), bag[0] = bag[1];
            ans += !(bag[0] - bag[1]);
        }
        return ans;
    }
};


// @lc app=leetcode id=2279 lang=cpp