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

bool solve()
{
    ll n = LL;
    if (n > 1099)
        return 1;
    for (int x = 0; x <= n; x += 111)
        if ((n - x) % 11 == 0)
            return 1;
    return 0;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}