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

string solve()
{
    int n = II, c = 0;
    string s = SS, ans = "";
    map<string, int> mp;
    for (int i = 1; i < n; i++)
    {
        string r = string(1, s[i - 1]) + string(1, s[i]);
        mp[r]++;
    }

    for (auto x : mp)
        if (c < x.second)
            c = x.second, ans = x.first;
    return ans;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}