#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

int n, m;
vector<string> grid;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = '#';  

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = cx + dx, ny = cy + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
                grid[nx][ny] = '#';  
                q.push({nx, ny});
            }
        }
    }
}

int countRooms() {
    int roomCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {  
                bfs(i, j);
                roomCount++;
            }
        }
    }
    return roomCount;
}

int main() {
    FAST_IO;
    cin >> n >> m;
    grid.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    cout << countRooms() << "\n";
    return 0;
}
