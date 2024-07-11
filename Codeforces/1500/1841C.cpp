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

void solve()
{
    ll n = LL, s1 = LL, s2 = LL;
    vv v;
    for (int i = 1; i <= n; i++)
        v.push_back({LL, i});
    sort(all(v), greater<vec>());
    
    vec a, b;
    for (int i = 0; i < n; i++)
    {
        ll c1 = v[i][0] * s1 * (a.size() + 1);
        ll c2 = v[i][0] * s2 * (b.size() + 1);
        if (c1 < c2)
            a.push_back(v[i][1]);
        else if (c1 > c2)
            b.push_back(v[i][1]);
        else if (c1 == c2)
            a.size() < b.size() ? a.push_back(v[i][1]) : b.push_back(v[i][1]);
    }
    
    cout << a.size() << " ";
    pv(a);
    cout << b.size() << " ";
    pv(b);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}