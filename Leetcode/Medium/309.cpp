#include "../../headers.h"

// Tabulation
// Time Complexity - O(N)
// Space Complexity - O(1)

// Explanation - In this solution to reduce the space complexity from O(N*2) to O(1), just take modulos of i with 3 as we only need
// 3 days at any given time i.e. current day, day + 1, day + 2
// It's a pretty smart way to reduce O(N) to O(1) space complexity

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        vector<vector<int>> dp(3, vector<int>(2, 0));
        for(int i = p.size() - 1; i >= 0; i--)
            for(int buy = 0; buy <= 1; buy++)
                if(buy)
                    dp[i % 3][buy] = max(-p[i] + dp[(i+1) % 3][0], 0 + dp[(i+1) % 3][buy]);
                else
                    dp[i % 3][buy] = max(p[i] + dp[(i+2) % 3][1], 0 + dp[(i+1) % 3][buy]);
        return dp[0][1];
    }
};



// Tabulation
// Time Complexity - O(N)
// Space Complexity - O(N*2)

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        vector<vector<int>> dp(p.size() + 2, vector<int>(2, 0));
        for(int i = p.size() - 1; i >= 0; i--)
            for(int buy = 0; buy <= 1; buy++)
                if(buy)
                    dp[i][buy] = max(-p[i] + dp[i+1][0], 0 + dp[i+1][buy]);
                else
                    dp[i][buy] = max(p[i] + dp[i+2][1], 0 + dp[i+1][buy]);
        return dp[0][1];
    }
};


// Memoization
// Time Complexity - O(N)
// Space Complexity - O(N*2) + recursive stack

class Solution
{
    int profit(vector<int> &p, int i, bool buy, vector<vector<int>> &dp)
    {
        if (i >= p.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        if (buy)
            return dp[i][buy] = max(-p[i] + profit(p, i + 1, false, dp), 0 + profit(p, i + 1, buy, dp));
        return dp[i][buy] = max(p[i] + profit(p, i + 2, true, dp), 0 + profit(p, i + 1, buy, dp));
    }

public:
    int maxProfit(vector<int> &p)
    {
        vector<vector<int>> dp(p.size(), vector<int>(2, -1));
        return profit(p, 0, true, dp);
    }
};


// Recursive
// Time Complexity - O(2^N)
// Space Complexity - O(N)

class Solution
{
    int profit(vector<int> &p, int i, bool buy)
    {
        if (i >= p.size())
            return 0;
        if (buy)
            return max(-p[i] + profit(p, i + 1, false), 0 + profit(p, i + 1, buy));
        return max(p[i] + profit(p, i + 2, true), 0 + profit(p, i + 1, buy));
    }

public:
    int maxProfit(vector<int> &p)
    {
        return profit(p, 0, true);
    }
};