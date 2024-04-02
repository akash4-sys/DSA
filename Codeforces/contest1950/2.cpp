#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<char>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vv solve()
{
    int n = II, m = 2 * n, st = 1;
    vv v(m, vec(m, '#'));
    for (int i = 0; i < m; i += 2)
    {
        int c = st;
        for (int j = 0; j < m; j += 2, c ^= 1)
            v[i][j] = v[i][j + 1] = v[i + 1][j] = v[i + 1][j + 1] = (c ? '#' : '.');
        st ^= 1;
    }
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