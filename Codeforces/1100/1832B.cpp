#ifdef __INTELLISENSE__
#include "../headers.h"
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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    int n = II, k = II;
    vec v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        v[i] = II;
    
    sort(all(v));
    for (int i = 1; i <= n; i++)
        v[i] += v[i - 1];
    
    ll ans = 0;
    for (int i = 0; i <= k; i++)
        ans = max(ans, v[n - i] - v[(k - i) * 2]);
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