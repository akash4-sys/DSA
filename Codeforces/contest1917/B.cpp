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

unordered_map<string, ll> dp;

ll rec(string &s)
{
    if (s.empty())
        return 0;
    if (dp.count(s))
        return 0;
    
    ll res = 1;
    // Type 1 operation
    char a = s.back();
    s.pop_back();
    res += rec(s);

    // Type 2 operation
    if (s.size())
    {
        char b = s.back();
        s.pop_back();
        s += a;
        res += rec(s);
        s.pop_back();
        s += b;
    }

    s += a;
    return dp[s] = res;
}

int solve()
{
    int n = II;
    string s = SS;
    reverse(all(s));
    return rec(s);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}