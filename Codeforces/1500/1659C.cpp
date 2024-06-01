#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

ll solve()
{
    ll n = LL, a = LL, b = LL, ans = LLONG_MAX, cost = 0;
    vector<ll> c(n + 1, 0), pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        c[i] = LL, pf[i] += pf[i - 1] + c[i];
    
    ans = min(ans, pf[n] * b);
    for (int i = 1; i <= n; i++) {
        cost += ((c[i] - c[i - 1]) * (a + b));
        ans = min(ans, (pf[n] - pf[i] - (c[i] * (n - i))) * b + cost);
    }
    return ans;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}