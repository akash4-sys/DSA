#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, sum = 0, ans = 0;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0, j = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        while (sum > x)
            sum -= v[j++];
        ans += (sum == x);
    }
    cout << ans;
    return 0;
}