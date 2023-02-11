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
#define pvv(a) { for(auto &v : a) pv(v) br; }
#define iv(v, n) { for(int i = 0; i < n; i++) cin >> v[i]; }

void solve()
{
    int n = II;
    if (n % 2 == 0)
    {
        pl("NO");
        return;
    }
    
    pl("YES");
    int m = (n - 1) / 2, l = (2 * m) + 1, r = l + 1;
    for (; r <= (4 * m) + 2; r++)
    {
        if (l < 0)
            l += (2 * m) + 1;
        pf(l)<<" "<<r<<endl;
        l -= 2;
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