#include "../../headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int minimumTime(vector<int> &a, vector<int> &b, int x)
    {
        int n = a.size(), asum = 0, bsum = 0;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            asum += a[i];
            bsum += b[i];
            v.push_back({b[i], a[i]});
        }
        sort(v.begin(), v.end());

        vector<int> dp(n + 1, 0);
        for (int j = 0; j < n; j++)
            for (int i = j + 1; i > 0; i--)
                dp[i] = max(dp[i], dp[i - 1] + (i * v[j][0]) + v[j][1]);

        for (int t = 0; t <= n; t++)
            if ((t * bsum) + asum - dp[t] <= x)
                return t;
        return -1;
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
    vector<vector<int>> v, dp;
    int maxSum(int t, int i)
    {
        if (t == 0 || i < 0)
            return 0;
        if (dp[t][i] != -1)
            return dp[t][i];

        int take = v[i][1] + (v[i][0] * t) + maxSum(t - 1, i - 1);
        return dp[t][i] = max(maxSum(t, i - 1), take);
    }

public:
    int minimumTime(vector<int> &a, vector<int> &b, int x)
    {
        int n = a.size(), asum = 0, bsum = 0;
        dp = vector(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++)
        {
            asum += a[i];
            bsum += b[i];
            v.push_back({b[i], a[i]});
        }

        sort(v.begin(), v.end());
        for (int t = 0; t <= n; t++)
            if ((t * bsum) + asum - maxSum(t, n - 1) <= x)
                return t;
        return -1;
    }
};