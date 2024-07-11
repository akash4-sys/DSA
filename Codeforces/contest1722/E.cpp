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
#define pl(x) cout << x << endl

class Prefix2D
{
    vv pf;
public:
    Prefix2D(vv &m)
    {
        pf = vv(m.size() + 1, vec(m[0].size() + 1, 0));
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                pf[i + 1][j + 1] = (pf[i + 1][j] + pf[i][j + 1] + m[i][j]) - pf[i][j];
    }

    ll sumRegion(int x1, int y1, int x2, int y2) {
        ll above = pf[x2 + 1][y1], left = pf[x1][y2 + 1], topLeft = pf[x1][y1];
        return pf[x2 + 1][y2 + 1] + topLeft - left - above;
    }
};

void solve()
{
    int n = II, q = II;
    vv v(1001, vec(1001, 0));
    for (int i = 0; i < n; i++) {
        int h = II, w = II;
        v[h][w] += h * w;
    }

    Prefix2D pf(v);
    while (q--)
    {
        int hs = II, ws = II, hb = II, wb = II;
        cout << pf.sumRegion(hs + 1, ws + 1, hb - 1, wb - 1) << "\n";
    }
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}