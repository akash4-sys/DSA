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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    vv v(5, vec(5, 0));
    int x = 0, y = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            v[i][j] = II;
            if (v[i][j] == 1)
                x = i, y = j;
        }
    
    return abs(x - 2) + abs(y - 2);
}

int main()
{
    fast;
    pl(solve());
    return 0;
}