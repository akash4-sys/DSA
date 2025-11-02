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
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II, m = II, q = II;
    vec a, b;
    vv c;
    for (int i = 0; i < n; i++)
        a.push_back(II), c.push_back({a.back(), 1});
    for (int i = 0; i < m; i++)
        b.push_back(II), c.push_back({b.back(), 0});
    
    sort(all(a), greater<ll>());
    sort(all(b), greater<ll>());
    sort(all(c), greater<vec>());

    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);
    c.insert(c.begin(), vec(2, 0));

    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= m; i++)
        b[i] += b[i - 1];
    for (int i = 1; i <= n + m; i++)
        c[i][0] += c[i - 1][0], c[i][1] += c[i - 1][1];
    
    auto query = [&](int x, int y, int z) {
        if (c[z][1] > x)
            return a[x] + b[z - x];
        if (z - c[z][1] > y)
            return b[y] + a[z - y];
        return c[z][0];
    };
    
    while (q--) {
        int x = II, y = II, z = II;
        pl(query(x, y, z));
    }
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}