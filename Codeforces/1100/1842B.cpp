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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void f(vec &v, int x, int &k)
{
    for (int i = 0; i < v.size(); i++)
    {
        int t = k | v[i], f = 1;
        for (int j = 0; j < 32 && f; j++)
            if (!(x & (1 << j)) && (t & (1 << j)))
                f = 0;
        if (!f)
            return;
        k = t;
    }
}

string solve()
{
    int n = II, x = II, k = 0;
    vec a(n), b(n), c(n);
    iv(a); iv(b); iv(c);
    f(a, x, k), f(b, x, k), f(c, x, k);
    return k == x ? "Yes" : "No";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}