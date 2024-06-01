#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a; a; })

int main()
{
    fast;
    ll n = LL, sum = 0, mx = 1e10;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        v[i] = LL, sum += v[i];

    ll ans = sum - n;
    if (n > 40) {
        cout << sum;
        return 0;
    }
    
    sort(v.begin(), v.end());
    for (ll c = 1; c <= 1e5; c++)
    {
        ll diff = 0, i = 0, p = 1;
        for (; i < n && p <= mx; i++, p *= c)
            diff += abs(v[i] - p);
        if (i == n)
            ans = min(ans, diff);
    }
    cout << ans;
    return 0;
}