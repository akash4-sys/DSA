#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

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
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

// ! Not My Code

ll solve()
{
    ll n = II, m = II, ans = 0, total = m * (m + 1) / 2;
    vector<ll> vis(n + m + 1, -1), a(n + 1), cnt(n + m + 1, 0);
    for (int i = 1; i <= n; i++)
        a[i] = II, vis[a[i]] = 0;

    for (int i = 1; i <= m; i++)
    {
        int p = II, v = II;
        if (vis[a[p]] >= 0)
            cnt[a[p]] += (i - vis[a[p]]);
        vis[a[p]] = -1;
        a[p] = v;
        vis[v] = i;
    }

    for (int i = 1; i <= n + m; i++)
    {
        if (vis[i] != -1)
            cnt[i] += (m + 1 - vis[i]);
        ll x = m + 1 - cnt[i];
        ans += total - (x * (x - 1) / 2);
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}