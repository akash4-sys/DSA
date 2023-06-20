#include "../../headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int paintWalls(vector<int> &c, vector<int> &t)
    {
        int n = t.size(), MX = INT_MAX;
        vector dp(n + 1, MX);
        for (int i = n - 1; i >= 0; i--)
            for (int tasks = n; tasks; tasks--)
            {
                int tasksLeft = tasks - t[i] - 1;
                int take = tasksLeft > 0 ? dp[tasksLeft] : 0;
                dp[tasks] = min(take != MX ? take + c[i] : MX, dp[tasks]);
            }
        return dp[n];
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
public:
    int paintWalls(vector<int> &c, vector<int> &t)
    {
        int n = t.size();
        vector dp(n + 1, vector<int>(n + 1, 0));
        for (int tasks = 0; tasks <= n; tasks++)
            dp[tasks][n] = INT_MAX;

        for (int i = n - 1; i >= 0; i--)
            for (int tasks = n; tasks; tasks--)
            {
                int tasksLeft = tasks - t[i] - 1;
                int take = tasksLeft > 0 ? dp[tasksLeft][i + 1] : 0;
                dp[tasks][i] = min(take != INT_MAX ? take + c[i] : INT_MAX, dp[tasks][i + 1]);
            }
        return dp[n][0];
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N^2) + auxiliary stack

class Solution
{
    int dp[501][501];
    int rec(vector<int> &c, vector<int> &t, int tasks, int i)
    {
        if (tasks <= 0)
            return 0;
        if (i == c.size())
            return INT_MAX;
        if (dp[tasks][i] != -1)
            return dp[tasks][i];

        int take = rec(c, t, tasks - t[i] - 1, i + 1);
        int notTake = rec(c, t, tasks, i + 1);
        return dp[tasks][i] = min(take != INT_MAX ? take + c[i] : INT_MAX, notTake);
    }

public:
    int paintWalls(vector<int> &c, vector<int> &t)
    {
        memset(dp, -1, sizeof(dp));
        return rec(c, t, c.size(), 0);
    }
};