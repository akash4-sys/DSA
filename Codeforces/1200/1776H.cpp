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

int solve()
{
    int n = II, i = n - 1, j = i;
    vec a(n), b(n);
    iv(a, n);
    iv(b, n);

    for (; i >= 0; i--)
    {
        for (; j >= 0 && b[i] != a[j]; j--);
        if (j < 0)
            return i + 1;
    }
    return 0;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}