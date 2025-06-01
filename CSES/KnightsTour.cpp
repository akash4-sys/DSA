#include <bits/stdc++.h>
using namespace std;

int a, b, vis[8][8];
int dirs[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int deg(int i, int j) {
    int res = 0;
    for (auto &d : dirs) {
        int x = i + d[0], y = j + d[1];
        res += (x >= 0 && x < 8 && y >= 0 && y < 8 && !vis[x][y]);
    }
    return res;
}

bool dfs(int i, int j)
{
    vector<vector<int>> v;
    for (auto &d : dirs) {
        int x = i + d[0], y = j + d[1];
        if (x >= 0 && x < 8 && y >= 0 && y < 8 && !vis[x][y])
            v.push_back({deg(x, y), x, y});
    }

    sort(v.begin(), v.end());
    for (auto &r : v) {
        int x = r[1], y = r[2];
        vis[x][y] = vis[i][j] + 1;
        if (vis[x][y] == 64 || dfs(x, y))
            return 1;
        vis[x][y] = 0;
    }
    return 0;
}

int main()
{
    cin >> a >> b;
    memset(vis, 0, sizeof(vis));
    vis[a - 1][b - 1] = 1;
    dfs(a - 1, b - 1);
    for (int i = 0; i < 8; i++)  {
        for (int j = 0; j < 8; j++)
            cout << vis[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
