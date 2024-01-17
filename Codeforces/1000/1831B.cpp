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

int solve()
{
    int n = II, ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0, cnt = 0, p = -1; i < n; i++)
    {
        int a = II;
        if (a != p)
            cnt = 0;
        mp[a] = max(mp[a], ++cnt);
        ans = max(ans, cnt);
        p = a;
    }

    for (int i = 0, cnt = 0, p = -1; i < n; i++)
    {
        int a = II;
        if (a != p)
            cnt = 0;
        ans = max(ans, ++cnt + mp[a]);
        p = a;
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