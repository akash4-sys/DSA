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
#define iv(v) { for(auto &x : v) cin >> x; }

string solve()
{
    ll n = LL, bx = LL;
    vec a(n);
    iv(a);
    ll m = LL, by = LL;
    vec b(m);
    iv(b);

    ll x = 0, y = 0, c = 1;
    for (int i = n - 1; i >= 0; i--)
        x += (a[i] * c), c *= bx;
    
    c = 1;
    for (int i = m - 1; i >= 0; i--)
        y += (b[i] * c), c *= by;
    return x == y ? "=" : (x > y ? ">" : "<");
}

int main()
{
    fast;
    pl(solve());
    return 0;
}