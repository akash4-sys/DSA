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

void solve()
{
    int n = II;
    string s = SS;
    vector<int> one_idx, zero_idx, ans;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            one_idx.push_back(i);
        else
            zero_idx.push_back(i);
    
    int p = one_idx.size(), q = zero_idx.size();
    if (!p || !q) {
        pl(0);
        return;
    }
    
    for (int i = 0, j = q - 1; i < p && j >= 0 && one_idx[i] < zero_idx[j]; i++, j--)
        ans.push_back(one_idx[i] + 1);
    
    if (ans.size()) {
        pl(1);
        for (int j = q - ans.size(); j < q; j++)
            ans.push_back(zero_idx[j] + 1);

        pf(ans.size());
        pv(ans);
        return;
    }
    pl(0);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}