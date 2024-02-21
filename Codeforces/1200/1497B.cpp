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

int solve()
{
    int n = II, m = II, ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[II % m]++;
    
    ans += mp.count(0);
    for (auto it : mp)
    {
        int a = it.first, b = m - a;
        if (mp.count(b) && mp[b] && mp[a] > 0)
        {
            if (mp[a] < mp[b])
                swap(a, b);
            mp[a] = mp[a] - mp[b] - 1;
            mp[b] = 0;
            ans += max(mp[a], 0) + 1;
        }
        else if (!mp.count(b) && b != m)
            ans += mp[a];
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}