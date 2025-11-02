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
    int n = II, m = II;
    vec a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++)
        a[i] = II, b[i] = II;
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int g = a[i] - a[i - 1];
        if (b[i] == b[i - 1]) {
            if (g % 2 == 0)
                ans += g;
            else ans += g - 1;
        }
        else {
            if (g % 2 == 0)
                ans += g - 1;
            else ans += g;
        }
    }

    int g = m - a.back();
    return ans + g;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}