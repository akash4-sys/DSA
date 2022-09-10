#include "../../headers.h"

// Divide and conqueor approach
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        int n = p.size();
        if (!n)
            return n;

        vector<int> left(n, 0), right(n, 0);
        int leftMin = p[0], rightMax = p[n - 1], i = 1, j = n - 2;

        while (i < n || j >= 0)
        {
            left[i] = max(left[i - 1], p[i] - leftMin);
            leftMin = min(leftMin, p[i]);
            right[j] = max(right[j + 1], rightMax - p[j]);
            rightMax = max(rightMax, p[j]);
            if (i < n)
                i++;
            if(j >= 0)
                j--;
        }

        int profit = right[0];
        for(int i = 1; i < n; i++)
            profit = max(profit, right[i] + left[i - 1]);
        return profit;
    }
};




// Time Complexity - O(N*4)
// Space Complexity - O(1)

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        vector<vector<int>> after(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));
        for (int i = p.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
                for (int cap = 1; cap <= 2; cap++)
                    if (buy)                        // Buy              // Don't Buy
                        curr[buy][cap] = max(-p[i] + after[0][cap], 0 + after[1][cap]); 
                    else                        //Sell                  // Don't sell
                        curr[buy][cap] = max(p[i] + after[1][cap - 1], 0 + after[0][cap]);
            after = curr;
        }
        return after[1][2];
    }
};



// Tabulation
// Time Complexity - O(N*2*3)
// Space Complexity - O(N^3)

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        vector<vector<vector<int>>> dp(p.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int i = p.size() - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
                for (int cap = 1; cap <= 2; cap++)
                    if (buy)
                        dp[i][buy][cap] = max(-p[i] + dp[i + 1][0][cap], 0 + dp[i + 1][1][cap]);
                    else
                        dp[i][buy][cap] = max(p[i] + dp[i + 1][1][cap - 1], 0 + dp[i + 1][0][cap]);
        }
        return dp[0][1][2];
    }
};



//  Memoization
// Time Complexity - O(N^2*3*3);
// Space Complexity - O(N^3) + Recurive Stack

class Solution
{
    int profit(vector<int> &p, int i, bool buy, int cap, vector<vector<vector<int>>> &dp)
    {
        if ((i == p.size()) || !cap)
            return 0;
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        if (buy) // buy                                    //don't buy
            return dp[i][buy][cap] = max(-p[i] + profit(p, i + 1, false, cap, dp), 0 + profit(p, i + 1, true, cap, dp));
        // sell                                      //don't sell
        return dp[i][buy][cap] = max(p[i] + profit(p, i + 1, true, cap - 1, dp), 0 + profit(p, i + 1, false, cap, dp));
    }

public:
    int maxProfit(vector<int> &p)
    {
        vector<vector<vector<int>>> dp(p.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return profit(p, 0, true, 2, dp);
    }
};

// Recursive
// Time Complexity - Exponential
// Space Complexity - Recurisve Stack

class Solution
{
    int profit(vector<int> &p, int i, bool buy, int cap)
    {
        if ((i == p.size()) || !cap)
            return 0;
        if (buy)
            return max(-p[i] + profit(p, i + 1, false, cap), 0 + profit(p, i + 1, true, cap));
        return max(p[i] + profit(p, i + 1, true, cap - 1), 0 + profit(p, i + 1, false, cap));
    }

public:
    int maxProfit(vector<int> &p)
    {
        return profit(p, 0, true, 2);
    }
};