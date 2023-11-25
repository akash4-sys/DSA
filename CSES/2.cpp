#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, sum = 0;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        long long x;
        cin >> x;
        sum += x;
    }
    cout << ((n * (n + 1)) / 2LL) - sum;
    return 0;
}