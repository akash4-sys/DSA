#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &a : v)
        cin >> a;
    
    ll p = INT_MAX, ans = 0;
    for (int i = n - 1; i >= 0; i--)
        ans += max(min(p - 1, v[i]), 0LL), p = max(min(p - 1, v[i]), 0LL);
    cout << ans;
    return 0;
}