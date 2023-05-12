#include "../../headers.h"

class Solution
{
    vector<vector<int>> dp;
    int rec(vector<int> &a, vector<int> &b, int i, int j)
    {
        if (i == a.size() || j == b.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (a[i] == b[j])
            return dp[i][j] = rec(a, b, i + 1, j + 1) + 1;
        return dp[i][j] = max(rec(a, b, i + 1, j), rec(a, b, i, j + 1));
    }
    
public:
    int maxUncrossedLines(vector<int> &a, vector<int> &b)
    {
        dp = vector(a.size(), vector<int>(b.size(), -1));
        return rec(a, b, 0, 0);
    }
};