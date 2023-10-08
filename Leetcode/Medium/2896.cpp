#include "../../headers.h"

class Solution
{
    int dp[501][501];
    int rec(vector<int> &v, int x, int l, int r)
    {
        if (l >= r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];

        int a = rec(v, x, l + 2, r) + min(v[l + 1] - v[l], x);
        int b = rec(v, x, l, r - 2) + min(v[r] - v[r - 1], x);
        int c = rec(v, x, l + 1, r - 1) + min(v[r] - v[l], x);
        return dp[l][r] = min({a, b, c});
    }

public:
    int minOperations(string s, string r, int x)
    {
        vector<int> v;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != r[i])
                v.push_back(i);
        
        memset(dp, -1, sizeof(dp));
        if (v.size() % 2)
            return -1;
        return x == 1 ? v.size() / 2 : rec(v, x, 0, v.size() - 1);
    }
};