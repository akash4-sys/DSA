#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
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

bool f(int a, int b, int c, int d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    if (c >= a && c <= b && (d <= a || d >= b))
        return 1;
    if (d >= a && d <= b && (c <= a || c >= b))
        return 1;
    return 0;
}

int solve()
{
    int a = II, b = II, c = II, d = II;
    return f(a, b, c, d) | f(c, d, b, a);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}