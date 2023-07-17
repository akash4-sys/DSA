#include "../../headers.h"

// Time Complexity - O(N.(K + logN))
// Space Complexity - O(N^2)

class Solution
{
    int search(vector<vector<int>> &v, int endTime, int i)
    {
        int l = i, r = v.size() - 1, res = -1;
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (v[mid][0] > endTime)
                res = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return res;
    }

public:
    int maxValue(vector<vector<int>> &v, int limit)
    {
        sort(v.begin(), v.end());
        vector dp(v.size() + 1, vector<int>(limit + 1, 0));
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int j = search(v, v[i][1], i + 1);
            for (int k = 1; k <= limit; k++)
            {
                int take = (j == -1 ? 0 : dp[j][k - 1]) + v[i][2];
                dp[i][k] = max(take, dp[i + 1][k]);
            }
        }
        return dp[0][limit];
    }
};

// Time Complexity - O(N.KlogN)
// Space Complexity - O(N^2)

class Solution
{
    int search(vector<vector<int>> &v, int endTime, int i)
    {
        int l = i, r = v.size() - 1, res = -1;
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (v[mid][0] > endTime)
                res = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return res;
    }

    int rec(vector<vector<int>> &v, vector<vector<int>> &dp, int k, int i)
    {
        if (!k || i == -1 || i == v.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];

        int j = search(v, v[i][1], i + 1);
        int take = rec(v, dp, k - 1, j) + v[i][2];
        return dp[i][k] = max(take, rec(v, dp, k, i + 1));
    }

public:
    int maxValue(vector<vector<int>> &v, int k)
    {
        sort(v.begin(), v.end());
        vector dp(v.size(), vector<int>(k + 1, -1));
        return rec(v, dp, k, 0);
    }
};

// @lc app=leetcode id=1751 lang=cpp