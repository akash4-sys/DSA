#include <bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II, m = II, q = II;
    vector<pair<int, int>> segs = {{{1, -q}, {m, m}, {n + q + 1, n}}};
    while (q--)
    {
        int a = II, ins = 0;
        for (auto &[l, r] : segs) {
            if (a < l) l = max(1, l - 1);
            else if (a > r) r = min(r + 1, n);
            else {
                ins = 1;
                if (l == r)
                    l = n + q, r = -q;
            }
        }

        if (ins) {
            segs[0] = {1, max(segs[0].second, 1)};
            segs[2] = {min(segs[2].first, n), n};
        }

        int lf = 0, rg = -1, ans = 0;
        for (auto &[l, r] : segs)
            if (l <= r) {
                if (l > rg) {
                    ans += max(0, rg - lf + 1);
                    lf = l;
                    rg = r;
                }
                rg = max(rg, r);
            }
        ans += max(rg - lf + 1, 0);
        cout << ans << " ";
    }
    br;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}