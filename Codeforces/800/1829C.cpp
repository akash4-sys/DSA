#ifdef __INTELLISENSE__
#include "../headers.h"
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
    vector<pair<int, string>> v;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        int m = II;
        string s = SS;
        int x = mp.count(s) ? mp[s] : INT_MAX;
        mp[s] = min(x, m);
    }

    int x = mp.count("11") ? mp["11"] : INT_MAX;
    if (!mp.count("01") || !mp.count("10"))
        return x == INT_MAX ? -1 : x;
    return min(x, mp["01"] + mp["10"]);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}