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
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

void dfs(vv &g, vec &checkLvl, int u, int par)
{
    checkLvl[u] = checkLvl[par] + 1;
    for (ll v : g[u])
        if (v != par)
            dfs(g, checkLvl, v, u);
}

int solve()
{
    int n = II;
    vv g(n + 1);
    for (int i = 2; i <= n; i++)
    {
        ll x = LL;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    vec checkLvl(n + 5, 0), nodesAtLvl(n + 5, 0);
    dfs(g, checkLvl, 1, 0);
    for (int lvl : checkLvl)
        nodesAtLvl[lvl]++;
    
    ll ans = 0, unpaired = 0;
    for (int i = n; i > 1; i--)
    {
        if (nodesAtLvl[i] > 1)
        {
            ll x = min(unpaired, nodesAtLvl[i] - 1);
            unpaired -= x;
            nodesAtLvl[i] -= x;
            ans += x;
        }
        ans += (nodesAtLvl[i] / 2);
        nodesAtLvl[i] %= 2;
        unpaired += nodesAtLvl[i];
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