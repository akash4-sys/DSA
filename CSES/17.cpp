#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int ans = 0;
bool safe(vector<string> &v, int n, int i, int j)
{
    if (v[i][j] == '*')
        return 0;

    for (int x = 0; x < j; x++)
        if (v[i][x] == 'Q')
            return 0;
    
    for (int x = i, y = j; x >= 0 && y >= 0; x--, y--)
        if (v[x][y] == 'Q')
            return 0;

    for (int x = i, y = j; x < n && y >= 0; x++, y--)
        if (v[x][y] == 'Q')
            return 0;
    return 1;
}

void queens(vector<string> &v, int n, int j)
{
    if (j >= n) {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++)
        if (safe(v, n, i, j))
        {
            v[i][j] = 'Q';
            queens(v, n, j + 1);
            v[i][j] = '.';
        }
}

int main()
{
    int n = 8;
    vector<string> v(n, string(n, '.'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    queens(v, n, 0);
    cout << ans;
    return 0;
}