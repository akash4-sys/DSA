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
    int n = II, k = II;
    vv v;
    for (int i = 1; i <= n; ++i) {
        int a = II, r = a % k ? (a % k) : k;
        v.push_back({r, i});
    }

    sort(all(v), [&](auto &a, auto &b){
        return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    });

    vector<int> ans;
    for (auto &r : v)
        ans.push_back(r[1]);
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--) {
        pv(solve());
        br;
    }
    return 0;
}