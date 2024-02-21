#include "../../headers.h"

class Solution
{
    int dp[2001][2001];
    int rec(vector<int> &v, int s, int l, int r)
    {
        if (l > r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];

        int res = 0;
        if (l + 1 <= r && v[l] + v[l + 1] == s)
            res = rec(v, s, l + 2, r) + 1;
        if (r - 1 >= l && v[r] + v[r - 1] == s)
            res = max(res, rec(v, s, l, r - 2) + 1);
        if (v[l] + v[r] == s)
            res = max(res, rec(v, s, l + 1, r - 1) + 1);
        return dp[l][r] = res;
    }

public:
    int maxOperations(vector<int> &v)
    {
        int n = v.size();
        memset(dp, -1, sizeof(dp));
        int a = rec(v, v[0] + v[1], 2, n - 1) + 1;
        memset(dp, -1, sizeof(dp));
        int b = rec(v, v[n - 1] + v[n - 2], 0, n - 3) + 1;
        memset(dp, -1, sizeof(dp));
        int c = rec(v, v[0] + v[n - 1], 1, n - 2) + 1;
        return max({a, b, c});
    }
};