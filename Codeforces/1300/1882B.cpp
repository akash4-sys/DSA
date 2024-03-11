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

int solve()
{
    int n = II, ans = 0;
    vv g(51), v(n);
    vec fq(51, 0);
    for (int i = 0; i < n; i++)
        for (int m = II; m; m--)
        {
            int a = II;
            v[i].push_back(a);
            g[a].push_back(i);
            ++fq[a];
        }
    
    for (int a = 1; a <= 50; a++)
        if (fq[a])
        {
            vec cnt = fq;
            for (int i : g[a])
                for (int x : v[i])
                    cnt[x]--;

            int unique = count_if(all(cnt), [&](int x){ return x > 0; });
            ans = max(ans, unique);
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