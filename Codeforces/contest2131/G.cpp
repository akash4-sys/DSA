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

const int mod = 1e9 + 7;
vec val(33);

ll solve()
{
    ll n = LL, k = LL, ans = 1;
    vec v(n);
    iv(v);
    sort(all(v));

    for (ll &a : v)
    {
        if (k == 0) break;
        if (a <= 32 && (1LL << (a - 1)) <= k) {
            (ans *= val[a]) %= mod;
            k -= (1 << (a - 1));
            continue;
        }

        (ans *= a) %= mod;
        k--;
        for (int i = 0; i < 32; i++)
            if (k & (1 << i))
                (ans *= val[i + 1]) %= mod;
        return ans;
    }
    return ans;
}

int main()
{
    fast;
    ll mul = 1;
    for (ll i = 1; i <= 32; i++) {
        val[i] = (mul * i) % mod;
        mul = (mul * val[i]) % mod;
    }

    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}