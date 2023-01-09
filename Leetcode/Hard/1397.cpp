#include "../../headers.h"

// Insane DP

class Solution
{
    int dp[501][501][2][2] = {0}, mod = 1e9 + 7;
    vector<int> lps;
    void generateLPS(string &s)
    {
        for (int i = 1, j = 0; i < s.size();)
            if (s[i] == s[j])
                lps[i++] = ++j;
            else if (j)
                j = lps[j - 1];
            else i++;
    }

    int dfs(string &s, string &r, string &e, int i, int j, int n, int k)
    {
        if (j == e.size())
            return 0;
        if (i == s.size())
            return 1;
        if (!dp[i][j][n][k])
        {
            for (char c = (n ? s[i] : 'a'); c <= (k ? r[i] : 'z'); c++)
            {
                int x = j;
                while (x > 0 && e[x] != c)
                    x = lps[x - 1];
                
                int next_j = c == e[x] ? x + 1 : 0;
                int next_n = n & (c == s[i]), next_k = k & (c == r[i]);
                dp[i][j][n][k] = (dp[i][j][n][k] + dfs(s, r, e, i + 1, next_j, next_n, next_k)) % mod;
            }
        }
        return dp[i][j][n][k];
    }

public:
    int findGoodStrings(int n, string s, string r, string e)
    {
        lps = vector<int>(e.size(), 0);
        generateLPS(e);
        return dfs(s, r, e, 0, 0, 1, 1);
    }
};
