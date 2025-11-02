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

ll cost(ll x) {
    ll p = pow(3, x);
    return (3 * p) + (x * (p / 3));
};

ll solve()
{
    ll n = II, k = II;
    if (k >= n)
        return n * 3;

    ll ans = 0;
    vec cnt(20, 0);
    while (n > 0)
    {
        ll x = 0, p = 1;
        while (p * 3 <= n) {
            p *= 3;
            x++;
        }

        n -= p;
        ans += cost(x);
        cnt[x]++;
        k--;
    }

    if (k < 0)
        return -1;
    
    for (int x = 18; x >= 0 && k > 1; x--) {
        ll c = min(cnt[x + 1], k / 2);
        if (c) {
            ans += (cost(x) * 3 - cost(x + 1)) * c;
            k -= c * 2;
            cnt[x] += c * 3;
        }
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}