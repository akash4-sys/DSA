#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, mx = 0;
    cin >> n;
    vector<int> v(n);
    for (int &a : v) {
        cin >> a;
        mx = max(mx, a);
    }

    v.push_back(0);
    sort(v.begin(), v.end());
    long long cnt = 0, m = mx * n + 1;
    vector<int> idx(m, INT_MAX);
    idx[0] = 0;

    for (int sum = 1; sum < m; sum++)
    {
        for (int i = 1; i < v.size() && v[i] <= sum; i++)
            if (idx[sum - v[i]] < i) {
                idx[sum] = i;
                break;
            }
        cnt += idx[sum] != INT_MAX;
    }

    cout << cnt << "\n";
    for (int i = 1; i < m; i++)
        if (idx[i] != INT_MAX)
            cout << i << " ";
    return 0;
}