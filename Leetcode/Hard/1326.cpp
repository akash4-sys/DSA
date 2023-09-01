#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int minTaps(int n, vector<int> &v)
    {
        vector<int> end(n + 1, 0);
        for (int i = 0; i <= n; i++)
            end[max(0, i - v[i])] = max(end[max(0, i - v[i])], min(n, i + v[i]));
        
        int ans = 0, curr_end = 0, max_end = 0;
        for (int i = 0; i <= n && curr_end != n; i++)
        {
            if (i <= curr_end)
                max_end = max(max_end, end[i]);
            if (i == curr_end)
                curr_end = max_end, ans++;
        }
        return curr_end != n ? -1 : ans;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    int dp[10001];
    int rec(vector<int> &v, int n, int r)
    {
        if (r == n)
            return 0;
        if (dp[r] != -1)
            return dp[r];

        int res = 1e5;
        for (int i = 0; i < v.size(); i++)
            if (v[i] != 0 && i - v[i] <= r && i + v[i] > r)
                res = min(res, rec(v, n, min(i + v[i], n)) + 1);
        return dp[r] = res;
    }

public:
    int minTaps(int n, vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));        
        int ans = rec(v, n, 0);
        return ans == 1e5 ? -1 : ans;
    }
};

// @lc app=leetcode id=1326 lang=cpp