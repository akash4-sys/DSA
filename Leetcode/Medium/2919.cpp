#include "../../headers.h"

class Solution
{
public:
    long long minIncrementOperations(vector<int> &v, int k)
    {
        long long a = 0, b = 0, c = 0, curr = 0;
        for (int &n : v) {
            curr = min({a, b, c}) + max(k - n, 0);
            a = b, b = c, c = curr;
        }
        return min({a, b, c});
    }
};


class Solution
{
public:
    long long minIncrementOperations(vector<int> &v, int k)
    {
        int n = v.size();
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[n] = dp[n - 1] = dp[n - 2] = 0;
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < min(i + 3, n); j++)
                dp[i] = min(dp[i], dp[j + 1] + max(k - v[j], 0));
        return dp[0];
    }
};


class Solution
{
    int n;
    long long dp[100001];

    long long rec(vector<int> &v, int k, int i)
    {
        if (i >= n - 2)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        long long res = LLONG_MAX;
        for (int j = i; j < min(i + 3, n); j++)
            res = min(res, rec(v, k, j + 1) + max(k - v[j], 0));
        return dp[i] = res;
    }

public:
    long long minIncrementOperations(vector<int> &v, int k)
    {
        memset(dp, -1, sizeof(dp));
        n = v.size();
        return rec(v, k, 0);
    }
};