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

bool poss(vv &v, int k)
{
    int l = 0, r = 0;
    for (auto &a : v)
    {
        l = max(l - k, a[0]);
        r = min(r + k, a[1]);
        if (l > r)
            return 0;
    }
    return 1;
}

int solve()
{
    int n = II, ans = 0;
    vv v(n, vec(2));
    for (int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1];
    
    int l = 0, r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (poss(v, mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
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