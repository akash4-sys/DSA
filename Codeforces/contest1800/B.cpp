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
    int n = II, k = II, chl[26] = {0}, chu[26] = {0};
    string s = SS;
    for (char &c : s)
        if (islower(c))
            chl[c - 'a']++;
        else
            chu[c - 'A']++;
    
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        int x = max(chl[i], chu[i]);
        int y = min(chl[i], chu[i]);
        ans += y;
        x -= y;
        int a = min(x / 2, k);
        k -= a;
        ans += a;
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