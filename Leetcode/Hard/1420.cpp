#include "../../headers.h"

class Solution
{
public:
    int numOfArrays(int n, int m, int K)
    {
        if (m < K)
            return 0;

        int mod = 1e9 + 7;
        vector dp(n + 1, vector(K + 1, vector<int>(m + 1, 0)));
        for (int mx = 0; mx <= m; mx++)
            dp[n][0][mx] = 1;

        for (int i = n - 1; i >= 0; i--)
            for (int k = 0; k <= K; k++)
                for (int mx = m; mx >= 0; mx--)
                    for (int j = 1; j <= m && (j <= mx || k > 0); j++)
                        (dp[i][k][mx] += dp[i + 1][k - (j > mx)][j > mx ? j : mx]) %= mod;
        return dp[0][K][0];
    }
};

// Time Complexity - O(N^3)
// Space Complexity - O(N^3)

class Solution
{
    int dp[51][51][101], mod = 1e9 + 7;
    int rec(int n, int m, int i, int k, int mx)
    {
        if (i == n && k == 0)
            return 1;
        if (i == n)
            return 0;
        if (dp[i][k][mx] != -1)
            return dp[i][k][mx];
        
        int res = 0;
        for (int j = 1; j <= m && (j <= mx || k > 0); j++)
            (res += rec(n, m, i + 1, k - (j > mx), j > mx ? j : mx)) %= mod;
        return dp[i][k][mx] = res;
    }

public:
    int numOfArrays(int n, int m, int k)
    {
        memset(dp, -1, sizeof(dp));
        return m < k ? 0 : rec(n, m, 0, k, 0);
    }
};