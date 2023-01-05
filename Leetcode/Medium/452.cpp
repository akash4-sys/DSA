#include "../../headers.h"

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &v)
    {
        int end = 0, ans = 0;
        sort(v.begin(), v.end(), [&](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        for (auto &p : v)
            if (ans == 0 || p[0] >= end)
                ans++, end = p[1];
        return ans;
    }
};


class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        map<int, int> mp;
        for (auto &p : v)
        {
            auto it = mp.lower_bound(p[0]);
            if (it == mp.end())
                mp[p[1]] = p[0];
            else if (it->second <= p[1])
            {
                int s = max(it->second, p[0]), e = min(it->first, p[1]);
                mp.erase(it);
                mp[e] = s;
            }
            else
                mp[p[1]] = p[0];
        }
        return mp.size();
    }
};

// @lc app=leetcode id=452 lang=cpp