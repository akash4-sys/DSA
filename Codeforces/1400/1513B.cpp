#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int mod = 1e9 + 7;

ll solve()
{
    ll n = II, x = INT_MAX, m = 0, fact = 1;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = II, x = min(x, (ll)v[i]);
    
    for (int a : v)
    {
        m += a == x;
        if ((a & x) != x)
            return 0;
    }

    for (ll i = 1; i <= n - 2; i++)
        fact = (fact * i) % mod;
    return (((m * (m - 1)) % mod) * fact) % mod;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}