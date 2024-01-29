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

void factors(ll x, vec &f)
{
    for (ll i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0) {
            if (x / i != i)
                f.push_back(x / i);
            f.push_back(i);
        }
}

ll solve()
{
    ll x = LL, n = LL, ans = 1;
    vec f;
    factors(x, f);
    for (ll k : f)
        if (n * k <= x)
            ans = max(ans, k);
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}