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

vec solve()
{
    int n = II;
    vv v(n, vec(n));
    for (auto &r : v)
        iv(r);
    
    vec ans(n * 2, 0), vis(n * 2 + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans[i + j - 1] = v[i - 1][j - 1], vis[v[i - 1][j - 1]] = 1;
    
    for (int i = 1; i < vis.size(); i++)
        if (!vis[i]) {
            ans[0] = i;
            break;
        }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}