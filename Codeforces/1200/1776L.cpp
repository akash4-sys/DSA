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

void solve()
{
    int n = II;
    string s = SS;
    int q = II, p = 0, m = 0;
    for (char &c : s)
        p += c == '+', m += c == '-';
    for (int i = 0; i < q; i++)
    {
        int a = II, b = II;
        if (a == b && p != m)
            pl("NO");
        else if (!(a % b) || !(b % a) || p == m || (a == m && b == p) || (a == p && b == m))
            pl("YES");
        else
            pl("NO");
    }
}

int main()
{
    fast;
    solve();
    return 0;
}