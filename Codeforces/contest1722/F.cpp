#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<string>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }

vv t = {{
    "...#",
    ".*..",
    ".**.",
    "...."
}, {
    "#...",
    "..*.",
    ".**.",
    "...."
}, {
    "....",
    ".**.",
    ".*..",
    "...#"
}, {
    "....",
    ".**.",
    "..*.",
    "#..."
}};

void del(vec &v, int k)
{
    int n = v.size(), m = v[0].size();
    for (int i = 0; i <= n - 4; i++)
        for (int j = 0; j <= m - 4; j++)
        {
            int res = 1;
            for (int xv = i, x = 0; x < 4; x++, xv++)
                for (int yv = j, y = 0; y < 4; y++, yv++)
                    if (t[k][x][y] != '#' && v[xv][yv] != t[k][x][y])
                        res = 0;
            
            if (!res)
                continue;
            for (int xv = i, x = 0; x < 4; x++, xv++)
                for (int yv = j, y = 0; y < 4; y++, yv++)
                    if (t[k][x][y] != '#')
                        v[xv][yv] = '.';
        }
}

bool solve()
{
    int n = II, m = II;
    vec v;
    v.push_back(string(m + 2, '.'));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s = "." + s + ".";
        v.push_back(s);
    }
    v.push_back(string(m + 2, '.'));

    if (n + 2 < 4 || m + 2 < 4)
        return 0;

    for (int i = 0; i < 4; i++)
        del(v, i);
    
    for (int i = 0; i < n + 2; i++)
        for (int j = 0; j < m + 2; j++)
            if (v[i][j] != '.')
                return 0;
    return 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}