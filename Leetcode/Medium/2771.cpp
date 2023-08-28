#include "../headers.h"

class Solution
{
public:
    int maxNonDecreasingLength(vector<int> &a, vector<int> &b)
    {
        int ans = 1, dp1 = 0, dp2 = 0;
        for (int i = 1; i < a.size(); i++)
        {
            int c00 = a[i - 1] <= a[i] ? dp1 + 1 : 1;
            int c01 = a[i - 1] <= b[i] ? dp1 + 1 : 1;
            int c10 = b[i - 1] <= a[i] ? dp2 + 1 : 1;
            int c11 = b[i - 1] <= b[i] ? dp2 + 1 : 1;
            dp1 = max(c00, c10);
            dp2 = max(c01, c11);
            ans = max({ans, dp1, dp2});
        }
        return ans;
    }
};


class Solution
{
public:
    int maxNonDecreasingLength(vector<int> &a, vector<int> &b)
    {
        vector dp(a.size() + 1, vector<int>(3, 0));
        for (int i = a.size() - 1; i >= 0; i--)
            for (int pi = 0; pi <= 2; pi++)
            {
                if (!pi || i == 0)
                    dp[i][pi] = max({dp[i + 1][0], dp[i + 1][1] + 1, dp[i + 1][2] + 1});
                else
                {
                    int prev = pi == 1 ? a[i - 1] : b[i - 1];
                    if (a[i] >= prev)
                        dp[i][pi] = dp[i + 1][1] + 1;
                    if (b[i] >= prev)
                        dp[i][pi] = max(dp[i][pi], dp[i + 1][2] + 1);
                }
            }
        return dp[0][0];
    }
};


class Solution
{
    int dp[100001][3];
    int rec(vector<int> &a, vector<int> &b, int i, int pi)
    {
        if (i == a.size())
            return 0;
        if (dp[i][pi + 1] != -1)
            return dp[i][pi + 1];
        if (pi == -1)
            return dp[i][pi + 1] = max({
                rec(a, b, i + 1, -1), 
                rec(a, b, i + 1, 0) + 1, 
                rec(a, b, i + 1, 1) + 1
            });

        int res = 0, prev = (pi ? b[i - 1] : a[i - 1]);
        if (a[i] >= prev)
            res = rec(a, b, i + 1, 0) + 1;
        if (b[i] >= prev)
            res = max(res, rec(a, b, i + 1, 1) + 1);
        return dp[i][pi + 1] = res;
    }

public:
    int maxNonDecreasingLength(vector<int> &a, vector<int> &b)
    {
        memset(dp, -1, sizeof(dp));
        return rec(a, b, 0, -1);
    }
};