#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })
#define pl(x) cout << x << endl
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    ll n = LL, K = LL, ans = 0;
    vector<ll> v(n);
    iv(v);
    if (K >= accumulate(v.begin(), v.end(), 0LL))
        return n;

    for (int i = 0, k = (K + 1) / 2; i < n && k >= v[i]; i++)
        k -= v[i], ans++;
    for (int i = n - 1, k = K / 2; i >= 0 && k >= v[i]; i--)
        k -= v[i], ans++;
    return ans;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        pl(solve());
    return 0;
}