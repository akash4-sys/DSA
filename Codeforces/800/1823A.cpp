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
    int n = II, k = II, m = n, q = 0;
    vec v(n, 1);
    for (int i = 0; i < n; i++)
    {
        int a = (m * (m - 1)) / 2;
        int b = (q * (q - 1)) / 2;
        if (a + b == k)
        {
            pl("YES");
            pv(v);
            br;
            return;
        }
        v[i] = -1;
        m--;
        q++;
    }
    pl("NO");
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}