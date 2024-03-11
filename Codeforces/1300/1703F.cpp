#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}

ll solve()
{
    ll n = LL, ans = 0;
    vec a(n + 1), v;
    for (int i = 1; i <= n; i++)
        a[i] = II;

    for (int i = 1; i <= n; i++)
        if (a[i] < i) {
            ans += (lower_bound(all(v), a[i]) - v.begin());
            v.push_back(i);
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