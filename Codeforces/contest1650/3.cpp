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

void solve()
{
    ll n = II, m = II, sum = 0;
    vv v(m), a;
    for (int i = 0; i < m; i++)
        v[i] = {II, II, i + 1}, swap(v[i][0], v[i][1]);
    
    sort(all(v));
    for (int i = 0; i < n * 2; i++)
        a.push_back({v[i][1], v[i][2]}), sum += v[i][0];
    sort(all(a));

    pl(sum);
    for (int i = 0; i < a.size() / 2; i++)
        cout << a[i][1] << " " << a[a.size() - i - 1][1] << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}