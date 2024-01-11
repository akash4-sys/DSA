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
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II;
    map<int, int> mp;
    vec v(n);
    for (int i = 0; i < n; i++)
        v[i] = II, mp[v[i]] = i;
    
    int mn = v[0], mn_idx = 0;
    mp.erase(v[0]);
    for (int i = 1; i < n; i++)
    {
        mp.erase(v[i]);
        if (v[i] > mn) {
            auto it = mp.upper_bound(v[i]);
            if (it != mp.begin())
                it--;
            if (it != mp.end() && v[i] > it->first) {
                pl("YES");
                pf(mn_idx + 1) << i + 1 << " " << it->second + 1 << endl;
                return;
            }
        }
        else
            mn = v[i], mn_idx = i;
    }
    pl("NO");
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}