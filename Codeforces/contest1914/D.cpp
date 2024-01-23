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
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

vec max3(vec &a)
{
    ll mx1 = -1, mx2 = -1, mx3 = -1;
    for (int i = 0; i < a.size(); i++)
        if (mx1 == -1 || a[i] > a[mx1])
            mx3 = mx2, mx2 = mx1, mx1 = i;
        else if (mx2 == -1 || a[i] > a[mx2])
            mx3 = mx2, mx2 = i;
        else if (mx3 == -1 || a[i] > a[mx3])
            mx3 = i;
    return {mx1, mx2, mx3};
}

ll solve()
{
    ll n = LL, ans = 0;
    vec a(n), b(n), c(n);
    iv(a);
    iv(b);
    iv(c);

    for (int x : max3(a))
        for (int y : max3(b))
            for (int z : max3(c))
                if (x != y && x != z && y != z)
                    ans = max(ans, a[x] + b[y] + c[z]);
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