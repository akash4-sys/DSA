#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

void solve()
{
    long long i, j, ans = 0;
    cin >> i >> j;
    long long n = max(i, j), c = min(i, j), l = (n - 1) * (n - 1), u = n * n;
    if (n % 2)
        ans = (i > j) ? l + c: u - c + 1;
    else
        ans = (i > j) ? u - c + 1 : l + c;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}