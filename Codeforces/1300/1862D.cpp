#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })
#define pl(x) cout << x << endl

ll solve()
{
    ll n = LL, sq = sqrtl(n * 2) - 1, x = 0;
    for (int a = sq; a <= sq + 2; a++)
        if (a * (a - 1LL) / 2LL <= n)
            x = a;
    
    ll ice_cream = x * (x - 1LL) / 2LL;
    return x + (n - ice_cream);
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        pl(solve());
    return 0;
}