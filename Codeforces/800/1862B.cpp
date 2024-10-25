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
    int n = II;
    vec v(n);
    iv(v);

    vec ans = {v[0]};
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
            ans.push_back(max(v[i] - 1, 1));
        ans.push_back(v[i]);
    }
    
    pl(ans.size());
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