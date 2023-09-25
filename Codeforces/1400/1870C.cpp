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
#define pl(x) cout << x << endl
#define br cout << endl
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II, k = II;
    vec v(n), sf(n), pf(n), ans(k + 1);
    iv(v);

    for (int i = 0, a = 0, b = 0; i < n; i++)
    {
        a = max(a, v[i]);
        b = max(b, v[n - i - 1]);
        pf[i] = a;
        sf[n - i - 1] = b;
    }

    for (int i = 0; i < n; i++)
    {
        int x = upper_bound(all(sf), v[i], greater<int>()) - sf.begin();
        int y = lower_bound(all(pf), v[i]) - pf.begin();
        ans[v[i]] = 2 * (x - y);
    }

    for (int i = 1; i <= k; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}