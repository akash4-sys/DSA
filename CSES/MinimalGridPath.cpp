#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int I(int i, int j) { return i * 10000 + j; }

int main()
{
    fast;
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &s : v) {
        cin >> s;
        s += 'a';
    }
    v.push_back(string(n + 1, 'a'));
    
    string ans = "";
    vector<int> q = {0};
    vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));
    while (!q.empty())
    {
        char c = 'Z';
        int idx, i, j;
        vector<int> t;
        while (!q.empty())
        {
            idx = q.back();
            q.pop_back();
            i = idx / 10000, j = idx % 10000;
            if (i == j && i == n - 1) {
                cout << ans + v[i][j];
                return 0;
            }
            if (!vis[i + 1][j])
                t.push_back(I(i + 1, j));
            if (!vis[i][j + 1])
                t.push_back(I(i, j + 1));
            vis[i + 1][j] = vis[i][j + 1] = 1;
            c = min({c, v[i + 1][j], v[i][j + 1]});
        }

        ans += v[i][j];
        for (auto &id : t)
            if (v[id / 10000][id % 10000] == c)
                q.push_back(id);
    }
    return 0;
}