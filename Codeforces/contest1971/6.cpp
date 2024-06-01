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

ll dist(ll x, ll y) {
    return (x * x) + (y * y);
}

ll solve()
{
    ll r = LL, ans = 0, R = r * r, R1 = (r + 1) * (r + 1), y = r;
    for (ll x = 0; x <= r; x++)
    {
        while (dist(x, y) >= R1)
            y--;
        for (ll y1 = y; dist(x, y1) >= R && y1; y1--)
            ans++;
    }
    return ans * 4;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        pl(solve());
    return 0;
}