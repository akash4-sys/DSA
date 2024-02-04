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

ll solve()
{
    ll a = LL, b = LL, r = LL, not_first_diff = 0, x = 0;
    if (a > b)
        swap(a, b);

    for (int i = 63; i >= 0; i--)
    {
        bool p = a & (1LL << i);
        bool q = b & (1LL << i);
        if (p != q && not_first_diff && !p && x + (1LL << i) <= r) {
            x += (1LL << i);
            a ^= (1LL << i);
            b ^= (1LL << i);
        }
        not_first_diff |= (p != q);
    }
    return b - a;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}