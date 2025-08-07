#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define iv(v) { for(auto &x : v) cin >> x; }
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << endl;}

void solve()
{
    int n = II;
    vector<int> v(n + 2), pf(n + 2, INT_MAX), sf(n + 2, 0);
    for (int i = 1; i <= n; i++)
        v[i] = II, pf[i] = min(pf[i - 1], v[i]);

    for (int i = n; i > 0; i--)
        sf[i] = max(sf[i + 1], v[i]);

    for (int i = 1; i <= n; i++)
        cout << (v[i] == pf[i] || v[i] == sf[i]);
    br;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}