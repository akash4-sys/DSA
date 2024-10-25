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
    ll n = II, k = II, g = 0;
    vec v(n);
    for (ll &a : v)
        a = LL, g = __gcd(g, a);
    if (n == 1)
        return v[0] < k ? k : k - 1;

    for (int i = 0; i < n; i++)
        v[i] = i * g;
    sort(all(v));
    v.push_back(1e16);

    ll last = -1;
    for (int i = 0; i < n; i++) {
        if (k <= v[i] - last - 1)
            break;
        k -= max(v[i] - last - 1, 0LL);
        last = v[i];
    }
    return last + k;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}