#ifdef __INTELLISENSE__
#include "../headers.h"
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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int dfs(vector<vector<int>> &m, int i, int j)
{
    if (i < 0 || j < 0 || i == m.size()|| j == m[0].size() || !m[i][j])
        return 0;
    int res = m[i][j];
    m[i][j] = 0;
    for (auto [dx, dy] : dirs)
        res += dfs(m, i + dx, j + dy);
    return res;
}

int solve()
{
    int n = II, m = II;
    vector<vec> grid(n, vec(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j])
            {
                int v = dfs(grid, i, j);
                ans = max(ans, v);
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