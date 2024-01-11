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
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, mx = 0, mn = INT_MAX;
    vec v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = II;
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }

    if (mn == v[0] || mx == v[n - 1])
        return mx - mn;

    int ans = max({v.back() - v[0], v.back() - mn, mx - v[0]});
    for (int i = 1; i < n; i++)
        if (v[i] < v[i - 1])
            ans = max(ans, v[i - 1] - v[i]);
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