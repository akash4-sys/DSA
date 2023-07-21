#include "../../headers.h"

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end(), [&](auto &a, auto &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<int> h;
        for (auto ev : v)
        {
            int i = lower_bound(h.begin(), h.end(), ev[1]) - h.begin();
            (i >= h.size()) ? h.push_back(ev[1]), 0 : h[i] = ev[1];
        }
        return h.size();
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &v)
    {
        int ans = 0;
        sort(v.begin(), v.end());
        vector<int> dp(v.size() + 1, 0);
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < i; j++)
                if (v[i][0] > v[j][0] && v[i][1] > v[j][1])
                    dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]);
        return ans + 1;
    }
};

// @lc app=leetcode id=354 lang=cpp