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

void solve()
{
    int n = II, d = INT_MAX, a = -1, b = -1;
    vec v(n);
    iv(v);

    for (int i = 0; i <= n; i++)
        if (abs(v[i % n] - v[(i + 1) % n]) < d)
        {
            d = abs(v[i % n] - v[(i + 1) % n]);
            a = i % n;
            b = (i + 1) % n;
        }
    pf(a + 1) << b + 1 << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}