#include "../../headers.h"

// Catalan Formula
class Solution
{
public:
    int numTrees(int n)
    {
        long ans = 1;
        for(int i = 0; i < n; i++)
            ans *= (4 * i + 2) / (i + 2.);
        return ans;
    }
};


// Tabulation approach
class Solution
{
public:
    int numTrees(int n)
    {
        int dp[20] = {0};
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};

// Time complexity - O(N^2)
// Space complexity - O(N) + stack space

class Solution
{
    int dp[20] = {0};
public:
    int numTrees(int n)
    {
        if (n <= 1)
            return 1;
        if (dp[n])
            return dp[n];
        for (int i = 1; i <= n; i++)
            dp[n] += numTrees(i - 1) * numTrees(n - i);
        return dp[n];
    }
};