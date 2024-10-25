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

bool solve()
{
    ll x = LL, N = 10000;
    for (ll a = 1; a <= N; a++) {
        ll a3 = a * a * a;
        if (a3 > x)
            break;

        ll b3 = x - a3;
        if (a3 > b3)
            break;

        ll b = cbrt(b3);
        if (b3 && b * b * b == b3)
            return 1;
    }
    return 0;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}