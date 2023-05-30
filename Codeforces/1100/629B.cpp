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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II;
    vector<pair<int, int>> m, f;
    for (int i = 0; i < n; i++)
    {
        char g;
        cin >> g;
        int a = II, b = II;
        if (g == 'M')
            m.push_back({a, b});
        else
            f.push_back({a, b});
    }

    int ans = 0;
    for (int i = 1; i <= 366; i++)
    {
        int males = 0, females = 0;
        for (auto [a, b] : m)
            males += (a <= i && i <= b);
        for (auto [a, b] : f)
            females += (a <= i && i <= b);
        ans = max(ans, min(males, females) * 2);
    }
    return ans;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}