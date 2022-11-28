#include "../../headers.h"

class Solution
{
public:
    int countPalindromes(string s)
    {
        int mod = 1e9 + 7, n = s.size();
        long ans = 0;
        for(int x = 0; x <= 9; x++)
            for(int y = 0; y <= 9; y++)
            {
                vector<long> p = {x, y, 0, y, x}, dp(6, 0);
                dp[5] = 1;
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < 5; j++)
                        if(s[i] - '0' == p[j] || j == 2)
                            dp[j] = (dp[j] + dp[j + 1]) % mod;
                ans = (ans + dp[0]) % mod;
            }
        return ans;
    }
};