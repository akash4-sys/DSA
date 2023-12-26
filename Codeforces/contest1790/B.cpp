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

vec solve()
{
    int n = II, sum = II, rsum = II;
    int x = sum - rsum, d = rsum / (n - 1), r = rsum % (n - 1);
    vec ans(n, d);
    ans[0] = x;
    for (int i = 1; r && i < n; i++)
        if (ans[i] + r <= x)
            ans[i] += r, r = 0;
        else
        {
            r -= x - ans[i];
            ans[i] = x;
        }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        pv(solve());
        br;
    }
    return 0;
}