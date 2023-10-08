#include "../../headers.h"

class Solution
{
    int dp[12][50][12][12][2][2];
    int rec(string &s, int k, int i, int n, int odd, int even, int zero, int tight)
    {
        if (i == s.size())
            return (!n && odd == even);
        
        if (dp[i][n][odd][even][zero][tight] != -1)
            return dp[i][n][odd][even][zero][tight];
        
        int ans = 0, r = tight ? s[i] - '0' : 9;
        for (int d = 0; d <= r; d++)
            if (zero && !d)
                ans += rec(s, k, i + 1, 0, 0, 0, 1, 0);
            else
            {
                int e = even + (d % 2 == 0), o = odd + (d % 2 != 0);
                ans += rec(s, k, i + 1, ((n * 10) + d) % k, o, e, 0, tight && (d == r));
            }
        return dp[i][n][odd][even][zero][tight] = ans;
    }

public:
    int numberOfBeautifulIntegers(int low, int high, int k)
    {
        string l = to_string(low - 1), r = to_string(high);
        memset(dp, -1, sizeof(dp));
        int left = rec(l, k, 0, 0, 0, 0, 1, 1);
        memset(dp, -1, sizeof(dp));
        return rec(r, k, 0, 0, 0, 0, 1, 1) - left;
    }
};