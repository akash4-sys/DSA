#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    map<long long, int> mp = {{0, 1}};
    long long sum = 0, ans = 0;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        sum += a;
        ans += mp.count(sum - x) ? mp[sum - x] : 0;
        mp[sum]++;
    }
    cout << ans;
    return 0;
}