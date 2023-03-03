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

double solve()
{
    int n = II, x = II, y = II;
    vec v(n);
    iv(v);
    sort(all(v), greater<int>());

    ll a = 0, b = 0, i = 0;
    for (; i < n && i < min(x, y); i++)
        a += v[i];
    for (int j = i; i < n && i < max(x, y) + j; i++)
        b += v[i];
    
    return ((double)a / min(x, y)) + ((double)b / max(x, y));
}

int main()
{
    fast;
    printf("%.8lf\n", solve());
    return 0;
}