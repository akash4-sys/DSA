#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, n, m;

int getSize(vv &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j])
        return 0;
    
    int res = 1;
    grid[i][j] = 0;
    for (auto &d : dirs)
        res += getSize(grid, i + d[0], j + d[1]);
    return res;
}

void setSize(vvv &g, int i, int j, int k, int col)
{
    if (i < 0 || j < 0 || i >= n || j >= m || !g[i][j][0] || g[i][j][0] == k)
        return;
    g[i][j] = {k, col};
    for (auto &d : dirs)
        setSize(g, i + d[0], j + d[1], k, col);
}

int largestComp(vvv &colGrid, vv &grid)
{
    int maxSize = 0, col = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j])
            {
                int sz = getSize(grid, i, j);
                setSize(colGrid, i, j, sz, col);
                colGrid[i][j][1] = col++;
                maxSize = max(maxSize, sz);
            }
    return maxSize;
}

int join(vvv &colGrid, int i, int j, set<int> &st)
{
    int sz = 0;
    for (auto &d : dirs)
    {
        int x = i + d[0], y = j + d[1];
        if (x >= 0 && x < n && y >= 0 && y < m && !st.count(colGrid[x][y][1]))
            sz += colGrid[x][y][0], st.insert(colGrid[x][y][1]);
    }
    return sz + (colGrid[i][j][0] == 0);
}

int convertRow(vvv &colGrid)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int sz = 0;
        set<int> st;
        for (int j = 0; j < m; j++)
            sz += join(colGrid, i, j, st);
        res = max(res, sz);
    }
    return res;
}

int convertCol(vvv &colGrid)
{
    int res = 0;
    for (int j = 0; j < m; j++)
    {
        int sz = 0;
        set<int> st;
        for (int i = 0; i < n; i++)
            sz += join(colGrid, i, j, st);
        res = max(res, sz);
    }
    return res;
}

int solve()
{
    n = II, m = II;
    char c;
    vvv colGrid(n, vv(m, vec(2, 0)));
    vv g(n, vec(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> c;
            colGrid[i][j][0] = g[i][j] = (c == '#');
        }
    
    int ans = largestComp(colGrid, g);
    return max({ans, convertRow(colGrid), convertCol(colGrid)});
}

int main()
{
    fast;
    for (int t = II; t--;)
        cout << solve() << "\n";
    return 0;
}