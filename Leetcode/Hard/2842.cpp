#include "headers.h"

class Solution
{
    using ll = long long;
    int mod = 1e9 + 7;

    ll power(ll a, ll b)
    {
        ll res = 1;
        for (a %= mod; b > 0; b >>= 1) {
                res = (res * a) % mod;
            a = (a * a) % mod;
        }
        return res;
    }

    ll fact(ll x)
    {
        ll res = 1;
        for (ll i = 1; i <= x; i++)
            res = (res * i) % mod;
        return res;
    }

    ll nCr(ll n, ll r)
    {
        ll res = fact(n);
        ll denominator = (fact(r) * fact(n - r)) % mod;
        return (res * power(denominator, mod - 2)) % mod;
    }

public:
    int countKSubsequencesWithMaxBeauty(string s, int k)
    {
        int n = 0, r = 0;
        vector<int> ch(26, 0), f(26);
        for (char c : s)
            ch[c - 'a']++;

        for (int i = 0; i < 26; i++)
            f.push_back(ch[i]);
        sort(f.begin(), f.end(), greater<int>());

        for (int i = 0; i < 26; i++)
        {
            n += f[i] == f[k - 1];
            r += (i < k && f[i] == f[k - 1]);
        }

        ll ans = nCr(n, r);
        for (int i = 0; i < k; i++)
            (ans *= f[i]) %= mod;
        return ans;
    }
};