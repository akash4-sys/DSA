#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

int main()
{
    fast;
    vector<ll> fact;
    for (ll i = 1, f = 1; i <= 14; i++)
        f *= i, fact.push_back(f);
    
    for (ll t = LL; t; t--)
    {
        ll n = LL, ans = 50;
        for (int mask = 0; mask < (1 << 14); mask++)
        {
            ll m = n, cnt = 0;
            for (int i = 0; i < 14; i++)
                if (mask & (1 << i))
                    m -= fact[i], cnt++;
            if (m >= 0)
                ans = min(ans, __builtin_popcountll(m) + cnt);
        }
        cout << ans << "\n";
    }
    return 0;
}