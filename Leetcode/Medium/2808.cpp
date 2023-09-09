#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int minimumSeconds(vector<int> &v)
    {
        int n = v.size(), ans = INT_MAX;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[v[i]].push_back(i);

        for (auto &[num, idx] : mp)
        {
            int time = (n - idx.back() + idx[0]) / 2;
            for (int i = 1; i < idx.size(); i++)
                time = max(time, (idx[i] - idx[i - 1]) / 2);
            ans = min(ans, time);
        }
        return ans;
    }
};

// @lc app=leetcode id=2808 lang=cpp