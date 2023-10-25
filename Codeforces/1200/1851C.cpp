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

string solve()
{
    int n = II, k = II, fi = -1, si = -1;
    vec v(n);
    iv(v);

    if (v[0] == v.back() && count(all(v), v[0]) >= k)
        return "YES";

    for (int i = 0, c = 0; i < n; i++)
    {
        c += v[i] == v[0];
        if (c == k)
        {
            fi = i;
            break;
        }
    }

    for (int i = n - 1, c = 0; i >= 0; i--)
    {
        c += v.back() == v[i];
        if (c == k)
        {
            si = i;
            break;
        }
    }

    if (fi == -1 || si == -1 || fi > si)
        return "NO";
    return "YES";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}