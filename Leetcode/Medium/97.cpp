#include "../../headers.h"

class Solution
{
    int dp[101][101];
    int dfs(string &s, string &r, string &p, int i, int j, int k)
    {
        if (i < 0 && j < 0 && k < 0)
            return 1;
        if (i >= 0 && j >= 0 && dp[i][j] != -1)
            return dp[i][j];
        if (i >= 0 && s[i] == p[k] && j >= 0 && r[j] == p[k])
            return dp[i][j] = dfs(s, r, p, i - 1, j, k - 1) | dfs(s, r, p, i, j - 1, k - 1);
        if (i >= 0 && s[i] == p[k])
            return dfs(s, r, p, i - 1, j, k - 1);
        if (j >= 0 && r[j] == p[k])
            return dfs(s, r, p, i, j - 1, k - 1);
        return 0;
    }

public:
    bool isInterleave(string s, string r, string p)
    {
        if (s.size() + r.size() != p.size())
            return 0;
        memset(dp, -1, sizeof(dp));
        return dfs(s, r, p, s.size() - 1, r.size() - 1, p.size() - 1);
    }
};