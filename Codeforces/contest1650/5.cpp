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
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int f(vec v, int d, int x)
{
    v.erase(v.begin() + x);
    int b = d + 1, maxb2 = d - v.back() - 1;
    for (int i = 1; i < v.size(); i++) {
        int gap = v[i] - v[i - 1] - 1;
        int b2 = (gap / 2) + (gap % 2 == 0 ? -1 : 0);
        b = min(b, gap);
        maxb2 = max(maxb2, b2);
    }
    return min(maxb2, b);
}

int solve()
{
    int n = II, d = II, b = d + 1, x = 0;
    vec v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        v[i] = II;
        if (v[i] - v[i - 1] - 1 <= b)
            x = i, b = v[i] - v[i - 1] - 1;
    }
    return max({b, f(v, d, x), f(v, d, x - 1)});
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}