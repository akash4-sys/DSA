#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl

bool solve()
{
    int n = II, a = II - 1, b = II - 1;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1, w = II;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    set<int> st;
    function<bool(int, int, int, int)> dfs = [&](int u, int ban, int x, int par) -> bool {
        if (ban == -1 && par != -1 && st.count(x))
            return 1;
        if (ban != -1)
            st.insert(x);

        int res = 0;
        for (auto [v, w] : g[u])
            if (v != par && v != ban)
                res |= dfs(v, ban, x ^ w, u);
        return res;
    };

    dfs(a, b, 0, -1);
    return dfs(b, -1, 0, -1);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}