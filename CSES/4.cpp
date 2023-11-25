#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    long long n, ans = 0, p = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if (p != -1 && p > x)
            ans += p - x, x = p;
        p = x;
    }
    cout << ans;
    return 0;
}