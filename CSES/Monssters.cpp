#include <bits/stdc++.h>
using namespace std;

int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
string s = "DRUL";

int f(int i , int j) {
    return i * 10000 + j;
}

int main()
{
    int n, m;
    cin >> n >> m;
    queue<int> player, monsters;
    vector v(n, vector<char>(m, '0'));
    vector path(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 'M')
                monsters.push(f(i, j));
            if (v[i][j] == 'A')
                player.push(f(i, j));
        }
    
    auto bfs = [&](queue<int> &q, int p) {
        for (int k = q.size(); k; k--)
        {
            int idx = q.front();
            q.pop();
            int i = idx / 10000, j = idx % 10000;
            if (p && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
                return idx;
            for (int l = 0; l < 4; l++)
            {
                int x = i + dirs[l][0], y = j + dirs[l][1];
                if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.') {
                    v[x][y] = '#';
                    path[x][y] = l;
                    q.push(f(x, y));
                }
            }
        }
        return -1;
    };
    
    while (!player.empty())
    {
        bfs(monsters, 0);
        int idx = bfs(player, 1);
        if (idx != -1)
        {
            cout << "YES\n";
            string ans = "";
            int i = idx / 10000, j = idx % 10000;
            while (v[i][j] != 'A') {
                int d = path[i][j];
                i -= dirs[d][0];
                j -= dirs[d][1];
                ans += s[d];
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n" << ans << "\n";
            return 0;
        }
    }
    cout << "NO";   
    return 0;
}