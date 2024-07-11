#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

void rotate(vector<vector<int>> &grid)
{
    int n = grid.size();
    for (int i = 0; i < n / 2; i++)
        for (int j = i; j < n - i - 1; j++)
        {
            int temp = grid[i][j];
            grid[i][j] = grid[n - j - 1][i];
            grid[n - j - 1][i] = grid[n - i - 1][n - j - 1];
            grid[n - i - 1][n - j - 1] = grid[j][n - i - 1];
            grid[j][n - i - 1] = temp;
        }
}

bool ok(vv &v) {
    return v[0][0] < v[0][1] && v[1][0] < v[1][1] && v[0][0] < v[1][0] && v[0][1] < v[1][1];
}

string solve()
{
    vv v(2, vec(2, 0));
    for (auto &r : v)
        iv(r);
    
    for (int cnt = 0; cnt < 4 && !ok(v); cnt++)
        rotate(v);
    return ok(v) ? "YES" : "NO";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}