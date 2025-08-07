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

ll f1(ll n, int x, int y)
{
    ll ans = 1;
    while (n > 1)
    {
        n /= 2;
        if (1 <= x && x <= n)
        {
            if (n < y && y <= n * 2) {
                y -= n;
                ans += (n * n * 3);
            }
        }
        else
        {
            x -= n;
            if (1 <= y && y <= n)
                ans += (n * n * 2);
            else {
                y -= n;
                ans += n * n;
            }
        }
    }
    return ans;
}

void f2(ll n, ll d)
{
    int x = 0, y = 0;
    while (n > 1)
    {
        n /= 2;
        ll m = n * n;
        if (m < d && d <= m * 2) {
            x += n;
            y += n;
            d -= m;
        }
        if (m * 2 < d && d <= m * 3)
            d -= (m * 2), x += n;
        if (m * 3 < d && d <= m * 4)
            d -= (m * 3), y += n;
    }
    cout << x + 1 << " " << y + 1 << "\n";
}

void solve()
{
    int N = II, q = II, n = 1 << N;
    while (q--) {
        string s = SS;
        if (s == "->") {
            int x = II, y = II;
            pl(f1(n, x, y));
        }
        else f2(n, LL);
    }
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}