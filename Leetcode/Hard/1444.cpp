#include "../../headers.h"

// Time Complexity - O(N^3)
// Space Complexity - O(N^3)

class Solution
{
public:
    int ways(vector<string> &p, int k)
    {
        int n = p.size(), m = p[0].size(), mod = 1e9 + 7;
        vector dp(k , vector(n, vector<int>(m, 0)));
        vector sf(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
            {
                sf[i][j] = (sf[i + 1][j] + sf[i][j + 1] + (p[i][j] == 'A')) - sf[i + 1][j + 1];
                dp[0][i][j] = sf[i][j] > 0;
            }
        
        for (int a = 1; a < k; a++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    for (int r = i + 1; r < n; r++)
                        if (sf[i][j] - sf[r][j] > 0)
                            (dp[a][i][j] += dp[a - 1][r][j]) %= mod;
                    for (int c = j + 1; c < m; c++)
                        if (sf[i][j] - sf[i][c] > 0)
                            (dp[a][i][j] += dp[a - 1][i][c]) %= mod;
                }
        return dp[k - 1][0][0];
    }
};



// Time Complexity - O(N^3)
// Space Complexity - O(N^3)

class Solution
{
    int mod = 1e9 + 7, n, m;
    vector<vector<int>> sf;
    vector<vector<vector<int>>> dp;
    int rc(int k, int i, int j)
    {
        if (!sf[i][j])
            return 0;
        if (!k)
            return 1;
        if (dp[k][i][j] != -1)
            return dp[k][i][j];
        int ans = 0;
        for (int r = i + 1; r < n; r++)
            if (sf[i][j] - sf[r][j] > 0)
                ans = (ans + rc(k - 1, r, j)) % mod;
        for (int c = j; c < m; c++)
            if (sf[i][j] - sf[i][c] > 0)
                ans = (ans + rc(k - 1, i, c)) % mod;
        return dp[k][i][j] = ans;
    }

public:
    int ways(vector<string> &p, int k)
    {
        n = p.size(), m = p[0].size();
        sf = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        dp = vector(k, vector(n, vector<int>(m, -1)));
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                sf[i][j] = (sf[i + 1][j] + sf[i][j + 1] + (p[i][j] == 'A')) - sf[i + 1][j + 1];
        return rc(k - 1, 0, 0);
    }
};