#include <bits/stdc++.h>
using namespace std;

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
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

bool isInside(ll circle_x, ll circle_y, ll rad, ll x, ll y)
{
    if ((x - circle_x) * (x - circle_x) +
        (y - circle_y) * (y - circle_y) <= rad)
        return 1;
    return 0;
}

bool solve()
{
    int n = II;
    vv v(n, vec(2, 0));
    for (auto &r : v)
        cin >> r[0] >> r[1];
    
    ll sx = LL, sy = LL, ex = LL, ey = LL;
    ll dist = ((sx - ex) * (sx - ex)) + ((sy - ey) * (sy - ey));
    for (auto &c : v)
        if (isInside(c[0], c[1], dist, ex, ey))
            return 0;
    return 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}