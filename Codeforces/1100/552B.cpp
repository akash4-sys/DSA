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

void solve()
{
    int n = II, w = 0, h = INT_MIN, hs = h;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({II, II});
        w += v.back().first;
        if (h < v.back().second)
            hs = h, h = v.back().second;
        else if (hs < v.back().second)
            hs = v.back().second;
    }
    
    for (int i = 0; i < n; i++)
    {
        long long a = w - v[i].first, b = v[i].second == h ? hs : h;
        pf(a * b)<<" ";
    }
    br;
}

int main()
{
    fast;
    solve();
    return 0;
}