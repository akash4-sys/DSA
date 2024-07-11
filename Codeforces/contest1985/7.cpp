#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

ll mod = 1e9 + 7;
ll power(ll a, ll b, ll res = 1) {
    for (a %= mod; b > 0; b >>= 1) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

ll solve() {
    ll l = LL, r = LL, k = LL, n = (9 / k) + 1;
    return ((power(n, r) - power(n, l)) % mod + mod) % mod;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}