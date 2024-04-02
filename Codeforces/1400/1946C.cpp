#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int solve()
{
    int n = II, k = II, l = 1, r = n / (k + 1) + 1;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto check = [&](int x) {
        int cnt = 0;
        function<int(int, int)> dfs = [&](int u, int par) -> int {
            int c = 1;
            for (int v : g[u])
                if (v != par)
                    c += dfs(v, u);
            
            if (c >= x && u != par)
                cnt++, c = 0;
            return c;
        };

        int nodes = dfs(0, 0);
        return cnt > k || (nodes >= x && cnt == k);
    };

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l - 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}