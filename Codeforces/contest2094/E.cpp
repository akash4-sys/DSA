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
    vec v(n), cnt(32, 0);
    iv(v);

    for (ll &a : v)
        for (int i = 0; i < 32; i++)
            if (a & (1LL << i))
                cnt[i]++;
    
    for (ll &a : v)
    {
        ll res = 0;
        for (int i = 0; i < 32; i++)
        {
            ll val = 1LL << i;
            if (a & val) {
                res += ((n - cnt[i]) * val);
            }
            else {
                res += (cnt[i] * val);
            }
        }
        ans = max(ans, res);
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