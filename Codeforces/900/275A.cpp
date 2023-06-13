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
#define pf(x) cout << x
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int v[3][3], ans[3][3], dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            v[i][j] = II, ans[i][j] = 1;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (v[i][j] % 2 != 0)
            {
                ans[i][j] = !ans[i][j];
                for (auto [dx, dy] : dirs)
                {
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && x < 3 && y >= 0 && y < 3)
                        ans[x][y] = !ans[x][y];
                }
            }
    pvv(ans);
}

int main()
{
    fast;
    solve();
    return 0;
}