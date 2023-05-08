#ifdef __INTELLISENSE__
#include "../headers.h"
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
    int n = II, m = II;
    vector<vec> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u = II, v = II;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    unordered_map<int, int> mp;
    for (int i = 0; i <= n; i++)
        mp[(int)g[i].size()]++;

    int x = 0, y = 0, b = mp[1];
    mp.erase(1);
    for (auto [f, c] : mp)
        x = max(x, c);
    x -= (b % x != 0);
    cout << x << " " << b / x << endl;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}