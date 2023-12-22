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
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    ll n = LL;
    vec v(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++)
        cin >> v[i];

    unordered_map<ll, ll> mp;
    for (int i = 1; i <= n * 2; i++)
        mp[v[i]] = i;
    
    ll minimumSize = 0, p = -1;
    for (int i = 1; i < v.size(); i++)
    {
        if (i > p)
            minimumSize++, p = mp[v[i]];
        else
            p = max(p, mp[v[i]]);
    }
    return {minimumSize};
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        pv(solve());
        br;
    }
    return 0;
}