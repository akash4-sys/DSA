#include "../../headers.h"

class Solution
{
public:
    int findMaxForm(vector<string> &v, int m, int n)
    {
        vector dp(m + 1, vector<int>(n + 1, 0));
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int ones = count(v[i].begin(), v[i].end(), '1'), zeros = v[i].size() - ones;
            for (int j = m; j >= zeros; j--)
                for (int k = n; k >= ones; k--)
                    dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
        }
        return dp[m][n];
    }
};



class Solution
{
    int dp[601][101][101];
    int rec(vector<vector<int>> &v, int i, int m, int n)
    {
        if (i == v.size())
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        
        int res = 0;
        if (m - v[i][0] >= 0 && n - v[i][1] >= 0)
            res += rec(v, i + 1, m - v[i][0], n - v[i][1]) + 1;
        return dp[i][m][n] = max(res, rec(v, i + 1, m, n));
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> v;
        for (auto &s : strs)
        {
            int ones = count(s.begin(), s.end(), '1'), a = s.size();
            v.push_back({a - ones, ones});
        }
        return rec(v, 0, m, n);
    }
};