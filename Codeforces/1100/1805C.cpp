#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II, m = II;
    vec k(n);
    iv(k);
    sort(all(k));

    for (int i = 0; i < m; i++)
    {
        ll a = LL, b = LL, c = LL, x = 4 * a * c;
        ll it = lower_bound(all(k), b) - k.begin();

        if (it < n && (k[it] - b) * (k[it] - b) < x)
            cout << "YES\n" << k[it] << "\n";
        else if (it > 0 && (k[it - 1] - b) * (k[it - 1] - b) < x)
            cout << "YES\n" << k[it - 1] << "\n";
        else 
            cout << "NO\n";
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