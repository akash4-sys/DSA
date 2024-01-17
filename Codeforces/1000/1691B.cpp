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
#define pv(v) {{ for(auto &x : v) pf(x); } br; }
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    int n = II;
    unordered_map<int, int> mp, idx;
    vec ans(n), v(n + 1);
    for (int i = 1; i <= n; i++) {
        int a = II;
        mp[a]++;
        idx[a] = i;
        v[i] = a;
    }

    for (int i = 0; i < n;)
    {
        if (mp[v[i + 1]] == 1)
            return {-1};
        
        int a = v[i + 1];
        ans[i++] = idx[a];
        for (int j = idx[a] - mp[a] + 1; j < idx[a] && i < n; j++)
            ans[i++] = j;
    }
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