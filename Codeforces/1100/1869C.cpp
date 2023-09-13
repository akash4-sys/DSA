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

vv solve()
{
    int n = II, m = II;
    vv v(n, vec(m, 0));
    for (int i = 0, k = 1; i < n && m != 1; i++, k++) {
        k = (k % m == 0) ? 1 : k;
        v[i][0] = k;
    }

    if (m == 1)
        pl(0);
    else if (m >= n + 1)
        pl(n + 1);
    else
        pl(m);

    for (int j = 1; j < m; j++)
        for (int i = 0; i < n; i++)
            v[i][j] = (v[i][j - 1] + 1) % m;
    return v;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pvv(solve());
    return 0;
}