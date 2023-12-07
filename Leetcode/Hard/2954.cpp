#include "../../headers.h"

#define ll long long

constexpr int N = 1e5;
ll mod = 1e9 + 7, fact[N + 1], inv_fact[N + 1];

class Solution
{
    ll power(ll a, ll b)
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

    ll binomial_coeff(int n, int k) {
        return max((((fact[n] * inv_fact[k]) % mod) * inv_fact[n - k]) % mod, 1LL);
    }

    void genFactorials()
    {
        if (fact[0])
            return;

        fact[0] = 1;
        for (int i = 1; i <= N; i++)
            fact[i] = (fact[i - 1] * i) % mod;
        
        inv_fact[N] = power(fact[N], mod - 2);
        for (int i = N - 1; i; i--)
            inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }

public:
    int numberOfSequence(int n, vector<int> &v)
    {
        genFactorials();
        ll ans = 1;
        for (int i = 1; i < v.size(); i++)
        {
            int grp = v[i] - v[i - 1] - 1;
            (ans *= power(2, max(grp - 1, 0))) %= mod;
            (ans *= binomial_coeff(v[i] - i, grp)) %= mod;
        }
        return (ans * binomial_coeff(n - v.size(), n - v.back() - 1)) % mod;
    }
};