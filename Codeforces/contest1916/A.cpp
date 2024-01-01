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

void solve()
{
    int n = II, k = II, a = 2023;
    vec b(n);
    iv(b);

    ll m = 1;
    for (int x : b)
        m *= x;
    
    if (a % m != 0)
    {
        pl("NO");
        return;
    }

    int p = 0;
    pl("YES");
    if (a != m) {
        pf(a / m);
        p = 1;
    }
    while (k-- > p)
        pf(1);
    br;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}