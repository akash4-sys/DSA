#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, ans = 1;
    cin >> n;
    vector<int>  v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v[a] = i;
    }
    for (int i = 2; i <= n; i++)
        ans += v[i] < v[i  - 1];
    cout << ans;
    return 0;
}