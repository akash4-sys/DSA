#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, ans = 0;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        ans += abs(v[i] - v[n / 2]);
    cout << ans;
    return 0;
}