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

string gen(string s, int n)
{
    string r = "";
    int cnt = 0;
    for (int i = 0; i < n; i++)
        r += s[i], cnt++, r += (cnt % 2 == 0) ? "-" : "";
    r.pop_back();
    return r;
}

string solve()
{
    int n = II;
    string s = SS;
    if (n <= 3)
        return s;
    if (n % 2 == 0)
        return gen(s, n);
    return gen(s, n - 3) + "-" + s.substr(n - 3, n);
}

int main()
{
    fast;
    pl(solve());
    return 0;
}