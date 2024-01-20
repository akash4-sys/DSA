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

vec solve()
{
    ll n = LL, d = 0, l = 0, r = 2;
    vec ans(n + 1);
    vector<pair<ll, ll>> v;
    for (int i = 1; i <= n; i++)
        v.push_back({LL, i});
    sort(all(v), greater<pair<ll, ll>>());

    ans[0] = 1;
    for (int i = 0; i < n; i++)
        if (i % 2 == 0) {
            ans[v[i].second] = r;
            d += (2 * abs(r - 1) * v[i].first);
            r++;
        }
        else {
            ans[v[i].second] = l;
            d += (2 * abs(l - 1) * v[i].first);
            l--;
        }

    pl(d);
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}