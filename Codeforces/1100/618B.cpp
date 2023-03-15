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
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    int n = II;
    vec ans(n, 0);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int m = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            int x = II;
            m = max(m, x);
        }
        mp[m]++;
        if (mp[m] == 2)
            ans[i] = n;
        else
            ans[i] = m;
    }
    return ans;
}

int main()
{
    fast;
    pv(solve());
    return 0;
}