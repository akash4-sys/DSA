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
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, k = II + 1, ans = n;
    vec v(n), mx1(k, -1), mx2(k, -1), col(k, -1);
    iv(v);

    auto update = [&](int d, int c) {
        if (d > mx1[c])
            mx2[c] = mx1[c], mx1[c] = d;
        else if (d > mx2[c])
            mx2[c] = d;
    };

    for (int i = 0; i < n; i++)
        update(i - col[v[i]] - 1, v[i]), col[v[i]] = i;

    for (int c = 1; c < k; c++) {
        update(n - col[c] - 1, c);
        ans = min(ans, max(mx1[c] / 2, mx2[c] == -1 ? n : mx2[c]));
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}