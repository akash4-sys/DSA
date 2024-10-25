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
    ll n = II, ans = 0;
    vv v(2, vec(n + 1, 0));
    for (int i = 0; i < n; i++) {
        ll x = LL, y = LL;
        v[y][x] = 1;
    }

    ll cnt[2] = {0};
    for (int i = 0; i < 2; i++)
        cnt[i] = accumulate(all(v[i]), 0);
    for (int i = 0; i <= n; i++)
        if (v[0][i] && v[1][i])
            ans += (cnt[0] + cnt[1] - 2);
    
    for (int y = 0; y < 2; y++)
        for (int x = 1; x < n; x++)
            if (v[y][x] && v[y ^ 1][x - 1] && v[y ^ 1][x + 1])
                ans++;
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}