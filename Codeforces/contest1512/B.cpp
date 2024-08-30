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

vector<string> solve()
{
    int n = II, x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j] == '*') {
                if (x1 == -1)
                    x1 = i, y1 = j;
                else
                    x2 = i, y2 = j;
            }
    
    if (x1 == x2) {
        if (x1 + 1 < n) {
            v[x1 + 1][y1] = v[x2 + 1][y2] = '*';
            return v;
        }
        if (x1 - 1 >= 0) {
            v[x1 - 1][y1] = v[x2 - 1][y2] = '*';
            return v;
        }
    }

    if (y1 == y2) {
        if (y1 + 1 < n) {
            v[x1][y1 + 1] = v[x2][y2 + 1] = '*';
            return v;
        }
        if (y1 - 1 >= 0) {
            v[x1][y1 - 1] = v[x2][y2 - 1] = '*';
            return v;
        }
    }
    v[x2][y1] = v[x1][y2] = '*';
    return v;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--) {
        auto v = solve();
        for (auto &s : v)
            pl(s);
    }
    return 0;
}