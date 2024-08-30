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

bool isPart(ll x, ll k) {
    return (x >= (1LL << k) && x <= (1LL << (k + 1)) - 1);
}

void solve()
{
    ll n = LL, q = LL;
    vec par(n - 1), p(n + 1);
    iv(par);
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    ll maxK = log2(n + 1);
    vec extra(maxK, 0);
    for (ll k = 0; k < maxK; k++)
        for (int i = 1 << k; i <= (1 << (k + 1)) - 1; i++)
            if (!isPart(p[i], k))
                extra[k]++;
    
    // pv(extra);
    while (q--)
    {
        ll i = II, j = II;
        ll a = p[i], b = p[j];
        ll k1 = log2(a), k2 = log2(b);
        
        pl(k1);
        pl(k2);
        if (extra[k1] && !isPart(a, k1))
            extra[k1]--;
        if (extra[k2] && !isPart(b, k2))
            extra[k2]--;
        
        if (!isPart(b, k1))
            extra[k1]++;
        if (!isPart(a, k2))
            extra[k2]++;
        
        swap(p[i], p[j]);
        pv(extra);
        if (accumulate(all(extra), 0) == 0)
            pl("YES");
        else
            pl("NO");
    }
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}