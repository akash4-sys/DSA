#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

int main()
{
    fast;
    ll n = LL, q = LL, sum = 0;
    vector<ll> a(n), v(n + 2, 0);
    iv(a);
    while (q--) {
        ll l = LL, r = LL;
        v[l]++, v[r + 1]--;
    }

    for (int i = 1; i <= n + 1; i++)
        v[i] += v[i - 1];
    
    sort(a.begin(), a.end(), greater<int>());
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++)
        sum += (a[i] * v[i]);
    cout << sum;
    return 0;
}