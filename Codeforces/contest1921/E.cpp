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
    ll n = LL, m = LL, x1 = LL, y1 = LL, x2 = LL, y2 = LL;
    if (x1 >= x2)
        return "Draw";
    
    ll d = x2 - x1, moves = (d + 1) / 2;
    ll l1 = max(y1 - moves, 1LL);
    ll l2 = max(y2 -  d / 2, 1LL);
    ll r1 = min(y1 + moves, m);
    ll r2 = min(y2 +  d / 2, m);

    if (d % 2 && l1 <= l2 && r2 <= r1)
        return "Alice";
    if (d % 2 == 0 && l2 <= l1 && r1 <= r2)
        return "Bob";
    return "Draw";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}