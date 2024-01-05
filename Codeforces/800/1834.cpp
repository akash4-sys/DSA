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

int solve()
{
    int n = II, pos = 0, neg = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a = II;
        pos += a > 0;
        neg += a < 0;
    }

    if (neg % 2)
        pos++, neg--, ans++;
    if (pos >= neg)
        return ans;

    int op = ceil((neg - pos) / 2.0);
    neg -= op, pos += op, ans += op;
    if (neg % 2)
        pos++, neg--, ans++;
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}