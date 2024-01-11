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

string solve()
{
    string s = SS;
    int ab = 0, ba = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        ab += s.substr(i, 2) == "ab";
        ba += s.substr(i, 2) == "ba";
    }

    if (ab == ba)
        return s;
    if (ab > ba && (s.substr(0, 2) == "ab" || s.substr(0, 2) == "aa"))
        s[0] = 'b';
    else if (ba > ab && (s.substr(0, 2) == "ba" || s.substr(0, 2) == "bb"))
        s[0] = 'a';
    return s;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}