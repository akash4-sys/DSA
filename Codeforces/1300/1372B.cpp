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
    int n = II, a = 1, b = n - 1;
    for (int i = 1, sq = sqrt(n); i <= sq; i++)
        if (n % i == 0) {
            a = n / i, b = n - a;
            break;
        }
    cout << a << " " << b << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}