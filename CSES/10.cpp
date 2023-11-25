#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    long long n, ans = 0;
    cin >> n;
    for (long long i = 5; i <= n; i *= 5)
        ans += n / i;
    cout << ans;
    return 0;
}