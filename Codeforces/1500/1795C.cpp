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
    vec a(n + 1, 0), b(n + 1, 0), mul(n + 2, 0), ans(n + 2, 0), pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
        a[i] = II;
    for (int i = 1; i <= n; i++) {
        b[i] = II;
        pre[i] += pre[i - 1] + b[i];
    }
    
    for (int i = 1; i <= n; i++)
        if (a[i] > b[i]) {
            int j = upper_bound(all(pre), a[i] + pre[i - 1]) - pre.begin();
            ans[j] += a[i] - pre[j - 1] + pre[i - 1];
            mul[i]++;
            mul[j]--;
        }
        else ans[i] += a[i];

    for (int i = 1; i <= n; i++) {
        mul[i] += mul[i - 1];
        ans[i] += b[i] * mul[i];
        cout << ans[i] << " ";
    }
    br;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}