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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v, n) { for(int i = 0; i < n; i++) cin >> v[i]; }

void solve()
{
    int n = II, m = INT_MAX, ans = 0;
    vec v(n);
    iv(v, n);
    sort(all(v));
    for (int i = 1; i < n; i++)
    {
        int x = abs(v[i] - v[i - 1]);
        if (x < m)
            m = x, ans = 1;
        else if (x == m)
            ans++;
    }
    pf(m)<<" "<<ans<<endl;
}

int main()
{
    fast;
    solve();
    return 0;
}