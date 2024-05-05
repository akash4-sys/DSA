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

vec solve()
{
    int n = II, x = 1;
    vv v, merged;
    for (int i = 0; i < n; i++)
        v.push_back({II, II, i});
    
    sort(all(v));
    for (auto &seg : v)
        if (merged.empty() || seg[0] > merged.back()[1])
            merged.push_back(seg);
        else {
            merged.back()[1] = max(merged.back()[1], seg[1]);
            merged.back().push_back(seg[2]);
        }
    
    vec ans(n, 1);
    for (auto &seg : merged) {
        for (int i = 2; i < seg.size(); i++)
            ans[seg[i]] = x + 1;
        x ^= 1;
    }

    if (merged.size() == 1)
        return {-1};
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}