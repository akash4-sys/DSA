#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int dirs[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int main()
{
    fast;
    int n = II, m = II;
    vector<vector<int>> v(n, vector<int>(m, 0)), vis = v;
    for (auto &r : v)
        for (int &a : r)
            a = II;
    
    function<int(int, int)> dfs = [&](int i, int j) -> int
    {
        int mask = v[i][j], res = 1;
        vis[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dirs[k][0], y = j + dirs[k][1], open = mask & (1 << k);
            if (min(x, y) >= 0 && x < n && y < m && !vis[x][y] && !open)
                res += dfs(x, y);
        }
        return res;
    };

    vector<int> ans;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!vis[i][j])
                ans.push_back(dfs(i, j));
    
    sort(ans.begin(), ans.end(), greater<int>());
    for (int a : ans)
        cout << a << " ";
    return 0;   
}