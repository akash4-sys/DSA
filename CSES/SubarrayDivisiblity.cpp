#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, sum = 0, ans = 0;
    cin >> n;
    vector<int> v(n);
    v[0] = 1;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        (sum += a % n + n) %= n;
        ans += v[sum]++;
    }
    cout << ans;
    return 0;
}