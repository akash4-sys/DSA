#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define LL ({ ll a; cin>>a ; a; })
#define pl(x) cout << x << endl

ll solve()
{
    ll n = LL, p = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll a = LL;
        a = min(p + 1, a);
        ans += a;
        p = a;
    }
    return ans;
}

int main()
{
    int tc = LL;
    while (tc--)
        pl(solve());
    return 0;
}