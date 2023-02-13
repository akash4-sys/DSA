#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v, n) { for(int i = 0; i < n; i++) cin >> v[i]; }

ll solve()
{
    ll a = LL, b = LL, n = LL, m = LL;
    if (m > n)
        return min(a * n, b * n);
    ll t = n / (m + 1), r = n % (m + 1);
    return min(a * r, b * r) + (t * min(a * m , b * (m + 1)));
}

int main()
{
    fast;
    int t = II;
    while (t--)
        pl(solve());
    return 0;
}