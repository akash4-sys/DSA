#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, st_pow = 0, power = 0;
    vv v(n);
    for (int i = 0; i < n; i++)
    {
        int armor = 0, m = II;
        for (int j = 0; j < m; j++) {
            int mon = II;
            armor = max(armor, mon - j);
        }
        v[i] = {armor + 1, m};
    }

    sort(all(v));
    for (auto &lvl : v)
    {
        if (power <= lvl[0])
            st_pow += (lvl[0] - power), power += (lvl[0] - power);
        power += lvl[1];
    }
    return st_pow;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}