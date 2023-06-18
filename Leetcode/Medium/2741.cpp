#include "headers.h"

class Solution
{
    int mod = 1e9 + 7, n, dp[16384][16];
    int rec(vector<int> &v, int i, int mask)
    {
        if (mask == (1 << v.size()) - 1)
            return 1;
        if (dp[mask][i] != -1)
            return dp[mask][i];
        
        int res = 0;
        for (int j = 0; j < n; j++)
            if (!mask || (!(mask & (1 << j)) && i != j && (v[i] % v[j] == 0 || v[j] % v[i] == 0)))
                (res += rec(v, j, mask | (1 << j))) %= mod;
        return dp[mask][i] = res;
    }

public:
    int specialPerm(vector<int> &v)
    {
        n = v.size();
        memset(dp, -1, sizeof(dp));
        return rec(v, 0, 0);
    }
};




class Solution
{
    int mod = 1e9 + 7;
    int rec(vector<int> &v, int len, int p, int mask)
    {
        if (len == v.size())
            return 1;
        
        int res = 0;
        for (int j = 0; j < v.size(); j++)
            if ((mask & (1 << j)) == 0 && (p % v[j] == 0 || v[j] % p == 0))
                (res += rec(v, len + 1, v[j], mask | (1 << j))) %= mod;
        return res;
    }

public:
    int specialPerm(vector<int> &v)
    {
        return rec(v, 0, 1, 0);
    }
};