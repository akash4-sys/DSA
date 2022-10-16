#include "../../headers.h"

class Solution
{
public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        int n = s.size();
        int dp[n + 1][k + 1];
        for (int i = n; i >= 0; i--)
            for (int j = 0; j <= k; j++)
            {
                if (i == n)
                {
                    dp[n][j] = 0;
                    continue;
                }
                dp[i][j] = j > 0 ? dp[i + 1][j - 1] : INT_MAX;
                int del = j, c = 0;
                for (int x = i; x < n && del >= 0; x++)
                    if (s[x] == s[i])
                    {
                        int y = ++c == 1 ? 1 : (c < 10 ? 2 : (c < 100 ? 3 : 4));
                        dp[i][j] = min(dp[i][j], dp[x + 1][del] + y);
                    }
                    else
                        del--;
            }
        return dp[0][k];
    }
};