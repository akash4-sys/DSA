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
    int n = II;
    vec a(n), ans;
    iv(a);
    vv v;
    for (int i = 0; i < n; i++)
        v.push_back({a[i] - II, i + 1});
    
    sort(all(v), greater<vector<int>>());
    ans.push_back(v[0][1]);
    for (int i = 1; i < n && v[i][0] == v[0][0]; i++)
        ans.push_back(v[i][1]);
    
    pl(ans.size());
    for (int i = ans.size() - 1; i >= 0; i--)
        pf(ans[i]);
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