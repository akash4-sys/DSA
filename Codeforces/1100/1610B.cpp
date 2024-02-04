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

bool check(vec &v, int x, int l, int r)
{
    for (; l <= r; l++, r--)
        if (v[l] != v[r])
        {
            if (!x)
                return check(v, v[l], l + 1, r) || check(v, v[r], l, r - 1);
            if (x == v[l])
                return check(v, x, l + 1, r);
            if (x == v[r])
                return check(v, x, l, r - 1);
            return 0;
        }
    return 1;
}

string solve()
{
    int n = II;
    vec v(n);
    iv(v);
    return check(v, 0, 0, n - 1) ? "YES" : "NO";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}