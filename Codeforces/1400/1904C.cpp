#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a; a; })

ll solve()
{
    ll n = LL, k = LL;
    vector<ll> v(n);
    for (ll &a : v)
        a = LL;
    if (k >= 3)
        return 0;
    
    sort(all(v));
    ll ans = v[0];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            ll d = v[j] - v[i];
            ans = min(ans, d);
            if (k == 2)
            {
                int x = lower_bound(all(v), d) - v.begin();
                ans = min(ans, v[x] - d);
                if (x >= 1)
                    ans = min(ans, d - v[x - 1]);
            }
        }
    return ans;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}