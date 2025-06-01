#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0, sum = 0;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a]++;
        mp[b]--;
    }

    for (auto [time, fq]: mp)
        sum += fq, ans = max(ans, sum);
    cout << ans;
    return 0;
}