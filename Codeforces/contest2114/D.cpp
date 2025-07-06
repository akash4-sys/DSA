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

ll solve()
{
    int n = II;
    vec x(n), y(n), p(4);
    for (int i = 0; i < n; i++)
        x[i] = II, y[i] = II;
    
    if (n < 3)
        return n;

    p[0] = max_element(all(x)) - x.begin();
    p[1] = min_element(all(x)) - x.begin();
    p[2] = max_element(all(y)) - y.begin();
    p[3] = min_element(all(y)) - y.begin();

    ll ans = LLONG_MAX;
    for (auto &k : p)
    {
        ll minX = INT_MAX, maxX = 0, minY = INT_MAX, maxY = 0;
        for (int i = 0; i < n; i++)
            if (i != k) {
                minX = min(minX, x[i]);
                maxX = max(maxX, x[i]);
                minY = min(minY, y[i]);
                maxY = max(maxY, y[i]);
            }
        
        ll res = (maxX - minX + 1) * (maxY - minY + 1);
        if (res == n - 1) {
            res = min((maxX - minX + 2) * (maxY - minY + 1), (maxX - minX + 1) * (maxY - minY + 2));
        }
        ans = min(ans, res);
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}