#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

bool check(vec &v, int w, int m, int x)
{
    vector<ll> st(v.size(), 0);
    ll curr = 0, mv = 0;
    for (int i = 0; i < v.size(); i++)
    {
        curr -= i - w >= 0 ? st[i - w] : 0;
        if (v[i] + curr < x)
        {
            st[i] = x - v[i] - curr;
            curr += st[i];
            mv += st[i];
        }
        if (mv > m)
            return 0;
    }
    return mv <= m;
}

ll solve()
{
    ll n = LL, m = LL, w = LL;
    vec v(n);
    iv(v);

    ll l = 1, r = 1e5 + 1e9, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(v, w, m, mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}