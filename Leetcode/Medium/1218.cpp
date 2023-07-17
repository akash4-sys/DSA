#include "../../headers.h"

class Solution
{
public:
    int longestSubsequence(vector<int> &v, int d)
    {
        unordered_map<int, int> dp;
        int ans = 0;
        for (int x : v)
        {
            dp[x] = dp.count(x - d) ? dp[x - d] + 1 : 1;
            ans = max(ans, dp[x]);
        }
        return ans;
    }
};

// TLE
class Solution
{
public:
    int longestSubsequence(vector<int> &v, int d)
    {
        vector<int> dp(v.size() + 1, 0);
        for (int i = v.size() - 1; i >= 0; i--)
            for (int j = i; j < v.size(); j++)
                if (i - 1 < 0 || v[i - 1] + d == v[j])
                    dp[i] = max(dp[i], dp[j + 1] + 1);
        return dp[0];
    }
};

// TLE
class Solution
{
    int rec(vector<int> &v, int d, vector<int> &dp, int i)
    {
        if (i == v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int res = 0;
        for (int j = i; j < v.size(); j++)
            if (i - 1 < 0 || v[i - 1] + d == v[j])
                res = max(res, rec(v, d, dp, j + 1) + 1);
        return dp[i] = res;
    }

public:
    int longestSubsequence(vector<int> &v, int d)
    {
        vector<int> dp(v.size(), -1);
        return rec(v, d, dp, 0);
    }
};