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

string solve()
{
    ll n = LL, k = LL, bp = LL, sp = LL;
    vec p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++)
        p[i] = LL;
    for (int i = 1; i <= n; i++)
        a[i] = LL;
    
    function<ll(int)> calc = [&](int i) -> ll {
        ll K = k;
        vec vis(n + 1, 0);
        ll sum = 0, score = 0;
        while (!vis[i] && K) {
            score = max(score, (K * a[i]) + sum);
            sum += a[i];
            K--;
            vis[i] = 1;
            i = p[i];
        }
        return score;
    };

    ll b = calc(bp), s = calc(sp);
    if (b == s)
        return "Draw";
    return b < s ? "Sasha" : "Bodya";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}