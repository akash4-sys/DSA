#include "../../headers.h"

class Solution
{
    int dp[101][101];
    int rec(string &s, int i, int k)
    {
        if (i == s.size() || s.size() - i <= k)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        
        int res = 100, ch[26] = {0}, mxf = 0;
        for (int j = i; j < s.size(); j++)
        {
            mxf = max(mxf, ++ch[s[j] - 'a']);
            int len = mxf == 1 ? 1 : (mxf < 10 ? 2 : (mxf < 100 ? 3 : 4));
            if (k >= (j - i - mxf + 1))
                res = min(res, rec(s, j + 1, k - (j - i - mxf + 1)) + len);
        }
        return dp[i][k] = res;
    }

public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        memset(dp, -1, sizeof(dp));
        return rec(s, 0, k);
    }
};