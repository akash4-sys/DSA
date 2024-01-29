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

vec solve()
{
    ll n = LL, m = LL, p = INT_MAX;
    vec a(n), q(m);
    iv(a); iv(q);

    vector<unordered_set<int>> v(31);
    for (int i = 0; i < n; i++)
        for (ll p = 1; p <= 30; p++)
            if (a[i] % (1LL << p) == 0)
                v[p].insert(i);
    
    for (ll x : q)
        if (x < p)
        {
            for (ll i : v[x])
            {
                a[i] += (1LL << (x - 1));
                if (a[i] % 2 == 0)
                    v[1].insert(i);
            }
            p = x;
        }
    return a;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}