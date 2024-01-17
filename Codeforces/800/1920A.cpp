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
    int n = II, a = 0, b = INT_MAX;
    vec v;
    for (int i = 0; i < n; i++)
    {
        int type = II, x = II;
        if (type == 1)
            a = max(a, x);
        else if (type == 2)
            b = min(b, x);
        else if (type == 3)
            v.push_back(x);
    }

    if (b < a)
        return 0;

    int cnt = b - a + 1;
    for (int x : v)
        if (x >= a && x <= b)
            cnt--;
    return cnt;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}