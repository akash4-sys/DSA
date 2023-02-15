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
#define iv(v, n) { for(int i = 0; i < n; i++) cin >> v[i]; }

string solve()
{
    int n = II, k = II, ch[26] = {0}, m[26] = {0}, g = 0;
    string s = SS;
    for (char c : s)
        ch[c - 'A']++;
    for (char c : s)
    {
        m[c - 'A']++;
        g += m[c - 'A'] == 1;
        if (g > k)
            return "YES";
        g -= (m[c - 'A'] == ch[c - 'A']);
    }
    return "NO";
}

int main()
{
    fast;
    pl(solve());
    return 0;
}