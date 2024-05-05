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

void solve()
{
    int n = II, m = 0;
    vec v(n), ans(n, 0);
    iv(v);

    for (int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31})
        for (int i = 0, first = 1; i < n; i++)
            if (v[i] % p == 0 && !ans[i])
                m += first, ans[i] = m, first = 0;
    
    pl(m);
    pv(ans);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}