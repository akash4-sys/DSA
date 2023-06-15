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

int solve()
{
    int n = II, mx = INT_MIN, mi = INT_MAX, l = 0, r = mi;
    for (int i = 0; i < n; i++)
    {
        int x = II;
        if (x > mx)
            mx = x, l = i;
        if (x <= mi)
            r = min(r, n - i - 1), mi = x;
    }
    if (l + r >= n)
        return l + r - 1;
    return l + r;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}