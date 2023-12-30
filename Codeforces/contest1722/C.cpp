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

vec solve()
{
    int k = II, n = II, d = 1, op = 0;
    vec v(n + 1, 0), ans;
    for (int i = 1; i <= n; d++)
    {
        v[i] = 1;
        op++;
        i += d;
    }

    int left = max(k - op, 0);
    for (int i = n; i > 0 && left; i--)
        if (!v[i])
            v[i] = 1, left--;

    for (int i = 1; i <= n && ans.size() < k; i++)
        if (v[i])
            ans.push_back(i);
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        pv(solve());
        br;
    }
    return 0;
}