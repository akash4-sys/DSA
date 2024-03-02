
#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << endl

/* ----------------- Solution 1  --------------------------- */


void levelOrder(vv &adj, vv &levels, int lvl, int u)
{
    if (levels.size() == lvl)
        levels.push_back({});
    levels[lvl].push_back(u);
    for (int v : adj[u])
        levelOrder(adj, levels, lvl + 1, v);
}

int solve()
{
    int n = II;
    vec par(n + 1, 0), cnt(n + 1, 0);
    vv adj(n + 1), lvl;
    for (int i = 2; i <= n; i++)
    {
        par[i] = II;
        adj[par[i]].push_back(i);
    }

    string s = SS;
    levelOrder(adj, lvl, 0, 1);
    for (int l = lvl.size() - 1; l >= 0; l--)
        for (int u : lvl[l])
        {
            cnt[u] += (s[u - 1] == 'W' ? 1 : -1);
            cnt[par[u]] += cnt[u];
        }
    return count(all(cnt), 0) - (!cnt[0]);
}



/* -------------------------------------------- */





/* ----------------- Solution 2  --------------------------- */

int rec(vv &adj, string &s, int &ans, int u)
{
    int cnt = s[u - 1] == 'W' ? 1 : -1;
    for (int v : adj[u])
        cnt += rec(adj, s, ans, v);
    ans += (!cnt);
    return cnt;
}

int solve2()
{
    int n = II, ans = 0;
    vv adj(n + 1);
    for (int i = 2; i <= n; i++)
        adj[II].push_back(i);
    string s = SS;
    rec(adj, s, ans, 1);
    return ans;
}

/* ------------------------------------------- */

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}