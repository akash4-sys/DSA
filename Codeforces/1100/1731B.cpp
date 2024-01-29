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

// ll direct()
// {
//     __int128 n = LL, mod = 1e9 + 7, a = n - 1;
//     __int128 diagonals = (n * (n + 1) * (n * 2 + 1)) / 6;
//     __int128 stairs = a * (a + 1) * (a + 2) / 3;
//     return (diagonals + stairs) * 2022 % mod;
// }

ll solve()
{
    ll n = LL, mod = 1e9 + 7;
    return n * (n + 1) % mod * (n * 4 - 1) % mod * 337 % mod;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        pl(solve());
    return 0;
}