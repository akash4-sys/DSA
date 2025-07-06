#include <bits/stdc++.h>
using namespace std;

int dirs[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, -1));
    queue<int> q;
    q.push(0);
    v[0][0] = 0;

    for (int moves = 1; q.size(); moves++)
        for (int k = q.size(); k; k--)
            {
                int idx = q.front(), i = idx / 10000, j = idx % 10000;
                q.pop();
                for (auto &[dx, dy] : dirs) {
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && x < n && y >= 0 && y < n && v[x][y] == -1)
                        v[x][y] = moves, q.push(x * 10000 + y);
                }
            }

    for (auto &r: v) {
        for (int &a : r)
            cout << a << " ";
        cout << "\n";
    }
    return 0;
}