#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
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

int solve()
{
    int n = II, k = II, l = 1, r = 1e9 + 1;
    vec v(n);
    for (int &a : v)
        a = II, a = min(a, n);

    while (l <= r)
    {
        ll x = (l + r) / 2;
        int cnt = 0, i = 0;
        vector<int> vis(n + 1, 0);
        for (int &a : v) {
            vis[a] = cnt + 1;
            while (i <= n && vis[i] == cnt + 1) i++;
            if (i >= x)
                cnt++, i = 0;
        }

        if (cnt >= k)
            l = x + 1;
        else
            r = x - 1;
    }
    return l - 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}