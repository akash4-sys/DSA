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

int rec(int n, int moves, int turn)
{
    if (n % 3 == 0 && turn)
        return 1;
    if (moves == 10)
        return 0;

    int r = n % 3, x = (((n / 3) + 1) * 3) - n;
    if (turn)
        return r < x ? rec(n - 1, moves + 1, 0) : rec(n + 1, moves + 1, 0);
    return r < x ? rec(n + 1, moves + 1, 1) : rec(n - 1, moves + 1, 1);
}

void solve()
{
    int n = II, ans = !rec(n, 0, 1);
    ans ? pl("First") : pl("Second");
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}