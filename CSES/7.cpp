#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    long long n;
    cin >> n;
    for (long long k = 1; k <= n; k++)
    {
        long long m = k * k, tot = m * (m - 1) / 2;
        long long red = 4 * (k - 1) * (k - 2);
        cout << tot - red << endl;
    }
    return 0;
}