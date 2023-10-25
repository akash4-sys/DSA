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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

double solve()
{
    double n = II, b = II * 1.0, h = II * 1.0;
    vector<double> v(n);
    iv(v);
    sort(all(v), greater<double>());

    double ans = 0.5 * b * h * n;
    for (int i = 1; i < n; i++)
        if (v[i - 1] - v[i] < h)
        {
            double d = v[i - 1] - v[i], cb = b - (d * 2.0);
            double ch = h - d;
            ans -= 0.5 * ch * cb;
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