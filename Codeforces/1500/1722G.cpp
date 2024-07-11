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
    int n = II, x1 = 0, x2 = 0, last = 1 << 30;
    for (int i = 0; i < n - 2; i++)
        x1 ^= i, x2 ^= (i + 1);
    
    for (int i = 0; i < n - 2; i++)
        cout << i + (x1 == 0) << " ";
    cout << last << " " << (x1 ? (last ^ x1) : (last ^ x2)) << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}