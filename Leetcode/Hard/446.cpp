#include "../../headers.h"

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &v)
    {
        int ans = 0, n = v.size();
        vector<unordered_map<long, int>> dp(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                long d = (long)v[i] - v[j];
                dp[i][d] += dp[j][d] + 1;
                ans += dp[j][d];
            }
        return ans;
    }
};


class Solution
{
    vector<unordered_map<long, int>> dp;
    int rec(vector<int> &v, int i, long d)
    {
        if (i == v.size())
            return 0;
        if (dp[i].count(d))
            return dp[i][d];
        
        int res = 0;
        for (int j = i + 1; j < v.size(); j++)
            if ((long)v[j] - v[i] == d)
                res += rec(v, j, d) + 1;
        return dp[i][d] = res;
    }

public:
    int numberOfArithmeticSlices(vector<int> &v)
    {
        dp = vector<unordered_map<long, int>>(v.size());
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++)
                ans += rec(v, j, (long)v[j] - v[i]);
        return ans;
    }
};