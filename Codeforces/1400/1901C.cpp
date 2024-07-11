#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}

void solve()
{
    int n = II, a = INT_MAX, b = 0;
    vec v(n), ans;
    for (int i = 0; i < n; i++)
        v[i] = II, a = min(a, v[i]), b = max(b, v[i]);
    
    while (a != b) {
        int x = a % 2;
        ans.push_back(x);
        a = (a + x) / 2;
        b = (b + x) / 2;
    }
    
    pl(ans.size());
    if (ans.size() <= n)
        pv(ans);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}