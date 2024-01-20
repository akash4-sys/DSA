#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void costPF(vec &v, vec &sum) {
    ll pd = INT_MAX;
    for (int i = 2; i < v.size(); i++) {
        ll cd = abs(v[i] - v[i - 1]);
        sum[i] = sum[i - 1] + (cd < pd ? 1 : cd);
        pd = cd;
    }
}

void costSF(vec &v, vec &sum) {
    ll pd = INT_MAX;
    for (int i = v.size() - 2; i > 0; i--) {
        ll cd = abs(v[i] - v[i + 1]);
        sum[i] = sum[i + 1] + (cd < pd ? 1 : cd);
        pd = cd;
    }
}

void solve()
{
    ll n = LL;
    vec v(n + 1), prefix_sum(n + 1, 0), suffix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        v[i] = LL;
    
    costPF(v, prefix_sum);
    costSF(v, suffix_sum);

    ll m = LL;
    while (m--)
    {
        ll l = LL, r = LL;
        if (l <= r)
            pl(prefix_sum[r] - prefix_sum[l]);
        else
            pl(suffix_sum[r] - suffix_sum[l]);
    }
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}