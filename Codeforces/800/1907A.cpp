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
    string s = SS;
    for (char c = 'a'; c <= 'h'; c++)
        if (c != s[0])
            cout << c << s[1] << '\n';
    for (int i = 1; i <= 8; i++)
        if (i != s[1] - '0')
            cout << s[0] << i << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}