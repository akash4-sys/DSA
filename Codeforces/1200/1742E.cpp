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
    ll n = LL, q = LL, mx = 0;
    vec v(n), ans, psum = {0};
    for (int i = 0; i < n; i++)
    {
        ll a = LL;
        mx = max(mx, a);
        v[i - 1] = mx;
        psum.push_back(psum.back() + a);
    }

    for (int i = 0; i < q; i++) {
        ll k = LL;
        int j = upper_bound(all(v), k) - v.begin() - 1;
        ans.push_back(psum[j]);
    }
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