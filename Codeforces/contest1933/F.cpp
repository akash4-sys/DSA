#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define vv vector<vec>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, m = II, ans = 1e8;
    vv v(n, vec(m, 0)), dist(n, vec(m, -1));
    for (auto &r : v)
        iv(r);
    
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    dist[0][0] = 0;

    auto dir = [&](int i, int j, int dx, int dy) {
        int x = (i + dx) % n, y = j + dy;
        if (dx == 2 && v[(i + 1) % n][j])
            return;
        if (y < m && !v[x][y] && dist[x][y] == -1)
            dist[x][y] = dist[i][j] + 1, q.emplace(x, y);
    };

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        dir(i, j, 2, 0);
        dir(i, j, 1, 1);
    }

    for (int i = 0; i < n; i++) {
        int d = dist[i][m - 1];
        if (d != -1) {
            d += ((i - d + 1) % n + n) % n;
            ans = min(ans, d);
        }
    }
    return ans == 1e8 ? -1 : ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}