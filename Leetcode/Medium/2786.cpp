#include "headers.h"

class Solution
{
public:
    long long maxScore(vector<int> &v, int x)
    {
        long long dp[2] = {-x, -x};
        dp[v[0] & 1] = v[0];
        for (int i = 1; i < v.size(); i++)
            dp[v[i] & 1] = max(dp[v[i] & 1], dp[(v[i] & 1) ^ 1] - x) + v[i];
        return max(dp[0], dp[1]);
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    long long maxScore(vector<int> &v, int x)
    {
        vector dp(v.size() + 1, vector<long long>(2, 0));
        dp[0][v[0] & 1] = v[0];

        for (int i = v.size() - 1; i >= 0; i--)
            for (int p = 0; p <= 1; p++)
                if ((v[i] & 1) == p)
                    dp[i][p] = dp[i + 1][p] + v[i];
                else
                    dp[i][p] = max(dp[i + 1][v[i] & 1] + v[i] - x, dp[i + 1][p]);
        return dp[0][v[0] & 1];
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    long long rec(vector<int> &v, vector<vector<long long>> &dp, int x, int i, int p)
    {
        if (i == v.size())
            return 0;
        if (dp[i][p] != -1)
            return dp[i][p];
        int currP = v[i] % 2 == 0;
        if (currP == p)
            return dp[i][p] = rec(v, dp, x, i + 1, p) + v[i];
        return dp[i][p] = max(rec(v, dp, x, i + 1, currP) + v[i] - x, rec(v, dp, x, i + 1, p));
    }

public:
    long long maxScore(vector<int> &v, int x)
    {
        vector dp(v.size(), vector<long long>(2, -1));
        return rec(v, dp, x, 1, v[0] % 2 == 0) + v[0];
    }
};