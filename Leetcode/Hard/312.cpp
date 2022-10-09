#include "../../headers.h"

// @ Chain Matrix Multiplication
// https://leetcode.com/discuss/general-discussion/1278305/all-about-matrix-chain-multiplication-easy

// Usually we find min in chain matrix multiplication but for this question it wants maximum

// Recursive with memoization
// Time Complexity O(N^3)
// Space Complexity O(N^2)

class Solution
{
public:
    int dp[501][501];
    int solve(int i, int j, vector<int> &v)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MIN;
        for (int k = i; k <= j - 1; k++)
            ans = max(solve(i, k, v) + solve(k + 1, j, v) + v[i - 1] * v[k] * v[j], ans);
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        v.insert(v.begin(), 1);
        v.push_back(1);
        return solve(1, v.size() - 1, v);
    }
};



// Pure Recursive
// Exponential Time complexity O(!N)
class Solution
{
    int solve(int i, int j, vector<int> v)
    {
        if (i >= j)
            return 0;
        int ans = INT_MIN;
        for (int k = i; k <= j - 1; k++)
            ans = max(solve(i, k, v) + solve(k + 1, j, v) + v[i - 1] * v[k] * v[j], ans);
        return ans;
    }

public:
    int maxCoins(vector<int> &v)
    {
        v.insert(v.begin(), 1); // these two lines are not part of matrix multiplication it's
        v.push_back(1);         // for this question
        return solve(1, v.size() - 1, v);
    }
};