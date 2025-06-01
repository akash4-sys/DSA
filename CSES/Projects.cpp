#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    sort(v.begin(), v.end());

    vector<long long> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> target = {v[i][1], 0, 0};
        int j = upper_bound(v.begin(), v.end(), target, [](auto &a, auto &b) {
            return a[0] < b[0];
        }) - v.begin();
        dp[i] = max(dp[i + 1], dp[j] + v[i][2]);
    }
    cout << dp[0];
    return 0;
}