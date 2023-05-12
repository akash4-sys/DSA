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

int solve()
{
    ll n = II, m = II, k = n * m;
    vec v(k);
    iv(v);
    
    sort(v.begin(), v.end());
    if (n > m)
        swap(n, m);

    ll l = v.back(), sl = v[k - 2], sm = v[0], ssm = v[1];
    ll x = (l * (k - n)) + (sl * (n - 1)) - (sm * (k - 1));
    ll y = (l * (k - 1)) - (sm * (k - n)) - (ssm * (n - 1));
    return max(x, y);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}