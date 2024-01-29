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
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vv gcdPairs;

int solve()
{
    int n = II, cost = -1;
    unordered_map<int, int> mp;
    vec v(n);
    for (int i = 0; i < n; i++)
        v[i] = II, mp[v[i]] = i + 1;
    
    for (auto &[a, i] : mp)
        for (int b : gcdPairs[a])
            if (mp.count(b))
                cost = max(cost, i + mp[b]);
    return cost;
}

int main()
{
    gcdPairs = vv(1001);
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            if (__gcd(i, j) == 1)
                gcdPairs[i].push_back(j);

    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}