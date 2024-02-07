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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    int n = II, x = 1, y = n, ans = 0;
    vec v(n);
    iv(v);
    for (int l = 0, r = n - 1; l <= r;)
    {
        int a;
        if (min(v[l], v[r]) <= x)
            x++, a = min(v[l], v[r]);
        else if (max(v[l], v[r]) >= y)
            y--, a = max(v[l], v[r]);
        else
            return {l + 1, r + 1};
        a == v[l] ? l++ : r--;
    }
    return {-1};
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}