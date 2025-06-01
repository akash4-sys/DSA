#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, ans = 1;
    cin >> n >> q;
    vector<int> v(n + 2, INT_MIN), a(n + 1);
    v[n + 1] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]] = i;
    }
    for (int i = 2; i <= n; i++)
        ans += v[i] < v[i  - 1];

    auto calc = [&](int i, int j) {
        int sum = (v[i - 1] > v[i]) + (v[i] > v[i + 1]) + (v[j] > v[j + 1]);
        return sum + (abs(i - j) > 1 && v[j - 1] > v[j]);
    };

    while (q--)
    {
        int i, j;
        cin >> i >> j;
        if (a[i] > a[j])
            swap(i, j);

        ans -= calc(a[i], a[j]);
        swap(v[a[i]], v[a[j]]);
        ans += calc(a[i], a[j]);
        swap(a[i], a[j]);
        cout << ans << "\n";
    }
    return 0;
}