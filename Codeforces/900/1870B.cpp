#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

void solve()
{
    int n = II, m = II, a = 0, b = 0;
    for (int i = 0; i < n; i++)
        a ^= II;
    for (int i = 0; i < m; i++)
        b |= II;
    
    if (n % 2 == 0)
        cout << ((a | b) ^ b) << " " << a << endl;
    else
        cout << a << " " << (a | b) << endl;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}