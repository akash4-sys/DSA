#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const vector<char> dir_chars = {'U', 'D', 'L', 'R'};
int n, m;
vector<vector<char>> grid;
int path[int(2e6)];

int f(int x, int y) {
    return x * 1000 + y;
}

pair<int, int> bfs(int a, int b) {
    queue<int> q;
    q.push(f(a, b));
    grid[a][b] = '#';
    while (!q.empty())
    {
        int i = q.front() / 1000, j = q.front() % 1000;
        q.pop();
        for (int d = 0; d < 4; ++d)
        {
            int x = i + dirs[d].first, y = j + dirs[d].second;
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#') {
                path[f(x, y)] = d;
                if (grid[x][y] == 'B')
                    return {x, y};
                grid[x][y] = '#';
                q.push(f(x, y));
            }
        }
    }
    return {-1, -1};
}

int main() {
    fast;
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    int start_x = -1, start_y = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start_x = i, start_y = j;
        }

    if (start_x == -1) {
        cout << "NO\n";
        return 0;
    }
    
    auto [x, y] = bfs(start_x, start_y);
    if (x == -1) {
        cout << "NO\n";
        return 0;
    }
    
    string ans = "";
    while (x != start_x || y != start_y) {
        int d = path[f(x, y)];
        ans += dir_chars[d];
        x -= dirs[d].first;
        y -= dirs[d].second;
    }
    
    reverse(ans.begin(), ans.end());
    cout << "YES\n" << ans.size() << "\n" << ans << endl;
    return 0;
}