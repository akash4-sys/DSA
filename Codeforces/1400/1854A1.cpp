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
    int n = II, j = -1;
    for (int i = 0; i < n; i++)
        if (II > 0)
            j = i;

    if (j == -1) {
        cout << n - 1 << "\n";
        for (int i = n - 1; i >= 1; i--)
            cout << i << " " << i + 1 << "\n";
        return;
    }

    cout << (n - 1) * 2 + 5 << "\n";
    for (int i = 0; i < 5; i++)
        cout << j + 1 << " " << j + 1 << "\n";
    
    j++;
    for (int i = 2; i <= n; i++) {
        cout << i << " " << j << "\n";
        cout << i << " " << j << "\n";
        j = i;
    }
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}