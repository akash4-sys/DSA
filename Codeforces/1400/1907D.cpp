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

bool possible(vv &v, int k)
{
    ll l = -k, r = k;
    for (auto &seg : v)
    {
        if ((seg[0] <= l && l <= seg[1]) ||
            (seg[0] <= r && r <= seg[1]) ||
            (l <= seg[0] && r >= seg[1])
        )
            l = max(l, seg[0]), r = min(r, seg[1]);
        else
            return 0;
        l -= k;
        r += k;
    }
    return 1;
}

int solve()
{
    int n = II, l = 0, r = 1e9 + 1;
    vv v(n, vec(2, 0));
    for (auto &seg : v)
        iv(seg);
    
    while (l <= r) {
        int mid = l + ((r - l) / 2);
        (possible(v, mid)) ? r = mid - 1 : l = mid + 1;
    }
    return l;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}