#include "../../headers.h"

class Solution
{
    int n;
    vector<vector<int>> dp, v, fact;

    int changes(string &s, int l, int r)
    {
        int m = r - l + 1, res = n;
        for (auto &f : fact[m])
        {
            int cnt = 0, len = m / f;
            for (int part = 0; part < f; part++)
                for (int i = 0; i < len / 2; i++)
                    cnt += (s[l + i * f + part] != s[l + (len - i - 1) * f + part]);
            res = min(res, cnt);
        }
        return res;
    }

    int rec(string &s, int k, int i)
    {
        if (i == n)
            return k == 0 ? 0 : n;
        if (k == 0)
            return n;
        if (dp[i][k] != -1)
            return dp[i][k];
        
        int res = n;
        for (int j = i; j < n; j++)
            res = min(res, rec(s, k - 1, j + 1) + v[i][j]);
        return dp[i][k] =  res;
    }

public:
    int minimumChanges(string &s, int k)
    {
        n = s.size();
        dp = v = vector(n, vector<int>(n, -1));
        fact = vector<vector<int>>(n + 1);

        for (int j = 1; j <= n; j++)
            for (int i = j + j; i <= n; i += j)
                fact[i].push_back(j);
        
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                v[i][j] = changes(s, i, j);
        return rec(s, k, 0);
    }
};