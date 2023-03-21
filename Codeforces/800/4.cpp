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
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<"\n"; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

vector<string> solve()
{
    int n = II, q = II;
    vec v(n), a(n);
    iv(v);
    int o = 0;
    for (int i = 0; i < n; i++)
    {
        o += v[i] % 2 != 0;
        a[i] = o;
    }

    vector<string> ans;
    for (int i = 0; i < q; i++)
    {
        int l = II - 1, r = II - 1, k = II;
        int op = a[r] - (l - 1 >= 0 ? a[l - 1] : 0), c = r - l + 1;
        if (k % 2 == 0)
            ans.push_back((o - op) % 2 == 0 ? "NO" : "YES");
        else
        {
            if (c % 2 == 0)
                ans.push_back((o - op) % 2 == 0 ? "NO" : "YES");
            else
                ans.push_back((c + (o - op)) % 2 ? "YES" : "NO");
        }
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}