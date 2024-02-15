#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define LL ({ ll a; cin>>a ; a; })
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll power(ll a, ll b, ll mod)
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

int main()
{
    fast;
    ll tc = LL, mod = 1e9 + 7;
    while (tc--) {
        ll n = LL, k = LL;
        cout << power(n, k, mod) << endl;
    }
    return 0;
}