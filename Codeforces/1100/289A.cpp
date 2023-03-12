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
#define LL ({ ll a; cin>>a ; a; })
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"

int solve()
{
    int n = II, k = II;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll x = LL, y = LL;
        sum += (y - x + 1);
    }
    return (k - (sum % k)) % k;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}