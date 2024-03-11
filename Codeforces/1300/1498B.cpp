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
    int n = II, width = II, cnt[31] = {0}, bits = 0, height = 0;
    for (int i = 0; i < n; i++) {
        int w = II, p = log2(w);
        bits += (++cnt[p] == 1);
    }

    for (; bits; height++)
        for (int i = 30, c = 0; i >= 0; i--, c *= 2)
        {
            c += !!(width & (1 << i));
            if (cnt[i])
            {
                if (c >= cnt[i])
                    c -= cnt[i], cnt[i] = 0;
                else
                    cnt[i] -= c, c = 0;
                bits -= (cnt[i] == 0);
            }
        }
    return height;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}