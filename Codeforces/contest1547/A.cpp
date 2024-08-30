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

int solve()
{
    int ax = II, ay = II;
    int bx = II, by = II;
    int fx = II, fy = II;
    int ans = abs(ax - bx) + abs(ay - by);
    if (ax != bx && ay != by)
        return ans;

    if (ax == bx && ax == fx && fy >= min(ay, by) && fy <= max(ay, by))
        return ans + 2;
    if (ay == by && ay == fy && fx >= min(ax, bx) && fx <= max(ax, bx))
        return ans + 2;
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}