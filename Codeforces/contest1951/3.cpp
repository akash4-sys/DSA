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

long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

ll solve()
{
    ll n = LL, m = LL, k = LL, w = ceil_div(k, m), ans = 0, p = 0;
    vec v(n);
    iv(v);
    sort(all(v));

    for (ll i = 0, K = k; i < w; i++) {
        ll c = min(K, m);
        ll curr_inf = p * c;
        K -= m;
        ans += (v[i] * c) + curr_inf;
        p += c;
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}