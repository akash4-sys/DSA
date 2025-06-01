#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, start = 0, ans = 0;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0, a, d; i < n; i++) {
        cin >> a >> d;
        v.push_back({a, d});
    }
    sort(v.begin(), v.end());

    for (auto &r : v) {
        start += r[0];
        ans += r[1] - start;
    }
    cout << ans;
    return 0;
}