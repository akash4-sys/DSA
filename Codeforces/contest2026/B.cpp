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
    vec v(n);
    iv(v);
    if (n == 1)
        return 1;

    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2)
            ans = max(ans, v[i + 1] - v[i]);
        return ans;
    }

    ans = LLONG_MAX;
    for (int i = 0; i < n; i += 2) {
        ll res = 0;
        for (int j = 0; j < n;) {
            if (j == i) {
                j++;
                continue;
            }
            if (j + 1 < n)
                res = max(res, v[j + 1] - v[j]);
            j += 2;
        }
        ans = min(ans, res);
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