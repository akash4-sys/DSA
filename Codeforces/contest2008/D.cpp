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
    int n = II;
    vec v(n + 1), vis2(n + 1, 0), ans(n + 1, 0), vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
        v[i] = II;
    string s = '#' + SS;

    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            int cnt = 0;
            for (int j = i; !vis2[j]; j = v[j]) {
                // cout << j << " ";
                cnt += ((s[j] - '0') == 0);
                vis2[j] = 1;
            }
            // br;
            for (int j = i; !vis[j]; j = v[j])
                vis[j] = 1, ans[j] = cnt;
        }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    br;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}