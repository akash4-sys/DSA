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
#define pl(x) cout << x << "\n"

// ! Did had the same idea couldn't code it, this code is from editorial

class Solution
{
    int longest_path = -1;
    vv g;
    vector<int> depth, par, n;
    void dfs(int u, int p)
    {
        depth[u] = depth[p] + 1;
        longest_path = max(longest_path, depth[u]);
        par[u] = p;
        for (auto &v : g[u])
            if (v != p)
                dfs(v, u);
    }

    vec move(int a, int b)
    {
        if (depth[a] > depth[b])
            swap(a, b);
        
        vec path = {b}, path2 = {a};
        int dist = depth[b] - depth[a];
        while (dist--) {
            b = par[b];
            path.push_back(b);
        }

        if (b == a)
            return path;
        
        while (par[a] != par[b]) {
            a = par[a];
            b = par[b];
            path2.push_back(a);
            path.push_back(b);
        }

        path.push_back(par[b]);
        while (path2.size())
            path.push_back(path2.back()), path2.pop_back();
        return path;
    }

public:
    ll solve()
    {
        int n = II, a = II, b = II;
        g = vv(n + 1);
        par = depth = vec(n + 1, 0);
        depth[0] = -1;
        for (int i = 1; i < n; i++) {
            int u = II, v = II;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (a == b) {
            dfs(a, 0);
            return (n - 1) * 2 - longest_path;
        }

        dfs(1, 0);
        vec path = move(a, b);
        int m = path.size();
        if (path[0] != a)
            reverse(all(path));

        int mid = path[(m - 1) / 2];
        longest_path = -1;
        dfs(mid, 0);
        return (n - 1) * 2 - longest_path + (m - 1 - (m - 1) / 2);
    }
};

int main()
{
    fast;
    int tc = II;
    while (tc--) {
        Solution sol;
        pl(sol.solve());
    }
    return 0;
}