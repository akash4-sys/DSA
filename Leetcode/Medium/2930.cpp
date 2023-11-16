#include "../../headers.h"

class Solution
{
    using ll = long long;
    ll power(ll a, ll b, ll mod = 1e9 + 7)
    {
        ll res = 1;
        for (a %= mod; b > 0; b >>= 1)
        {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
        }
        return res;
    }

public:
    int stringCount(int n)
    {
        ll mod = 1e9 + 7;
        ll totalWays = power(26, n);
        ll single = (n + 75) * power(25, n - 1);
        ll pairs = (2 * n + 72) * power(24, n - 1);
        ll triplets = (n + 23) * power(23, n - 1);
        return ((totalWays - single + pairs - triplets) % mod + mod) % mod;
    }
};



enum Masks {
    LEET = 0b1111,
    L = 0b1000,
    FIRST_E = 0b0100,
    SECOND_E = 0b0010,
    T = 0b0001,
    mod = 1000000007
};

class Solution
{
    long long dp[100005][16];
    long long rec(int n, int i, int mask)
    {
        if (i == n)
            return mask == LEET;
        if (dp[i][mask] != -1)
            return dp[i][mask];

        long long res = rec(n, i + 1, mask | L) + rec(n, i + 1, mask | T);
        if (mask & FIRST_E)
            res += rec(n, i + 1, mask | SECOND_E);
        else
            res += rec(n, i + 1, mask | FIRST_E);
        res += (23LL * rec(n, i + 1, mask)) % mod;
        return dp[i][mask] = res % mod;
    }

public:
    int stringCount(int n)
    {
        memset(dp, -1, sizeof(dp));
        return rec(n, 0, 0);
    }
};