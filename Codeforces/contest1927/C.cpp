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

string solve()
{
    int n = II, m = II, k = II, x = 0, y = 0, h = k / 2, c = 0;
    map<int, int> a, b;
    for (int i = 0; i < n; i++)
        a[II]++;
    for (int i = 0; i < m; i++)
        b[II]++;
    
    for (auto &it : a)
        if (it.first <= k)
            b.count(it.first) ? c++ : x++;

    for (auto &it : b)
        y += (it.first <= k && !a.count(it.first));
    
    c = c - abs(h - x) - abs(h - y);
    return c >= 0 ? "YES" : "NO";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}