#include "../../headers.h"


// Memoization
class Solution 
{
    bool recurse(vector<vector<int>> &dp, vector<int> &v, int a, int b, int t, int i, int j)
    {
        if(i == v.size() || j < 0)
            return a > b;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(t == 0)
            return dp[i][j] = recurse(dp, v, a + v[i], b, 1, i + 1, j) || recurse(dp, v, a + v[j], b, 1, i, j - 1);
        return dp[i][j] = recurse(dp, v, a, b + v[i], 0, i + 1, j) || recurse(dp, v, a, b + v[j], 0, i, j - 1);
    }
public:
    bool stoneGame(vector<int>& v) 
    {
        vector<vector<int>> dp(v.size(), vector<int>(v.size(), 0));
        return recurse(dp, v, 0, 0, 0, 0, v.size() - 1);
    }
};


// Recursion
class Solution
{
    bool recurse(vector<int> v, int a, int b, int t, int i, int j)
    {
        if (i == v.size() || j < 0)
            return a > b;
        if (t == 0)
            return recurse(v, a + v[i], b, 1, i + 1, j) || recurse(v, a + v[j], b, 1, i, j - 1);
        return recurse(v, a, b + v[i], 0, i + 1, j) || recurse(v, a, b + v[j], 0, i, j - 1);
    }

public:
    bool stoneGame(vector<int> &v)
    {
        return recurse(v, 0, 0, 0, 0, v.size() - 1);
    }
};