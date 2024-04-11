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
    int n = II, ans = 0, m = n * 2;
    vec v(m), a;
    iv(v);
    sort(all(v));
    for (int i = 0; i < n; i++)
        a.push_back(v[i]), a.push_back(v[m - i - 1]);

    for (int i = 2; i < m; i += 2)
        ans += (a[i] - a[i - 2]) + (a[i - 1] - a[i + 1]);
    
    pl(ans);
    for (int i = 0; i < m; i += 2)
        pf(a[i]) << a[i + 1] << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}