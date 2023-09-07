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
    int n = II, ans = 0;
    vv v;
    for (int i = 0; i < n; i++)
        v.push_back({II, II});
    
    for (auto p : v)
    {
        int rt = 0, d = 0, u = 0, l = 0;
        for (auto r : v)
        {
            rt |= (r[0] > p[0] && r[1] == p[1]);
            l |= (r[0] < p[0] && r[1] == p[1]);
            d |= (r[0] == p[0] && r[1] < p[1]);
            u |= (r[0] == p[0] && r[1] > p[1]);
        }
        ans += (rt && d && u && l);
    }
    return ans;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}