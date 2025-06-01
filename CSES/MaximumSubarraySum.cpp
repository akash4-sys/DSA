#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, maxSum = LLONG_MIN, sum = 0, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        maxSum = max(maxSum, sum + a);
        sum = max(sum + a, 0LL);
    }
    cout << maxSum;
    return 0;
}