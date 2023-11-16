#include "../../headers.h"

class Solution
{
public:
    int lengthOfLongestSubsequence(vector<int> &v, int target)
    {
        vector<int> dp(target + 1, 0);
        for (int num : v)
            for (int t = target; t >= num; t--)
                if (t - num == 0 || dp[t - num])
                    dp[t] = max(dp[t], 1 + dp[t - num]);
        return dp[target] ? dp[target] : -1;
    }
};

class Solution
{
    int dp[1001][1001];
    int rec(vector<int> &v, int t, int i)
    {
        if (t == 0)
            return 0;
        if (i == v.size())
            return INT_MIN;
        if (dp[i][t] != -1)
            return dp[i][t];

        int res = INT_MIN;
        if (t >= v[i])
            res = rec(v, t - v[i], i + 1) + 1;
        return dp[i][t] = max(res, rec(v, t, i + 1));
    }

public:
    int lengthOfLongestSubsequence(vector<int> &v, int t)
    {
        memset(dp, -1, sizeof(dp));
        int ans = rec(v, t, 0);
        return ans <= 0 ? -1 : ans;
    }
};