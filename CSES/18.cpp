#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

long long calc(long long n)
{
    long long m = 1, d = 1;
    while (n - (m * d * 9) > 0)
        n -= (m * d * 9), d++, m *= 10;

    int i = n % d == 0 ? d : n % d;
    long long num = m + (n / d) - (i == d);
    for (int j = i; j < d; num /= 10, j++);
    return num % 10;
}

int main()
{
    long long q, n;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> n;
        cout << calc(n) << endl;
    }
    return 0;
}