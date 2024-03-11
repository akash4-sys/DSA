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
#define mod 998244353

vec solve()
{
    string s = SS;
    ll k = 1, n = s.size(), p = 0;
    for (int i = 1; i < n; i++)
        k += (s[i] != s[i - 1]);
    
    ll op = n - k, fact = 1, ways = 1;
    for (ll i = 1; i <= op; i++)
        fact = fact * i % mod;
    
    for (ll i = 1; i < n; i++)
        if (s[i] != s[i - 1]) {
            ways = ways * (i - p) % mod;
            p = i;
        }
    ways = (ways * (n - p) % mod) * fact % mod;
    return {op, ways};
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}