#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    string stoneGameIII(vector<int> &v)
    {
        int n = v.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            for (int j = i, sum = 0; j < min(i + 3, n); j++)
            {
                sum += v[j];
                dp[i] = max(dp[i], sum - dp[j + 1]);
            }
        return dp[0] == 0 ? "Tie" : dp[0] < 0 ? "Bob" : "Alice";
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    string stoneGameIII(vector<int> &v)
    {
        int n = v.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            for (int j = i, sum = 0; j < min(i + 3, n); j++)
            {
                sum += v[j];
                dp[i] = max(dp[i], sum - dp[j + 1]);
            }

        return dp[0] == 0 ? "Tie" : dp[0] < 0 ? "Bob" : "Alice";
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    int dfs(vector<int> &v, vector<vector<int>> &dp, int i, int turn)
    {
        if (i == v.size())
            return 0;
        if (dp[i][turn] != -1)
            return dp[i][turn];
        
        int sum = 0, res = turn ? INT_MAX : INT_MIN;
        for (int j = i; j < min(i + 3, (int)v.size()); j++)
        {
            sum = turn ? sum - v[j] : sum + v[j];
            int x = sum + dfs(v, dp, j + 1, !turn);
            res = turn ? min(res, x) : max(res, x);
        }
        return dp[i][turn] = res;
    }

public:
    string stoneGameIII(vector<int> &v)
    {
        vector dp(v.size(), vector<int>(2, -1));
        int ans = dfs(v, dp, 0, 0);
        return ans == 0 ? "Tie" : ans < 0 ? "Bob" : "Alice";
    }
};