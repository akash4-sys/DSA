#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    long long n, sum = 0, ans = LLONG_MAX;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    for (long long i = 0; i < (1 << n); i++)
    {
        long long a = 0;
        for (long long j = 0; j < n; j++)
            if (i & 1 << j)
                a += v[j];
        ans = min(ans, abs(a * 2 - sum));
    }
    cout << ans;
    return 0;
};