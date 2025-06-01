#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, j = 0, a; i < n; i++) {
        cin >> a;
        if (mp.count(a) && mp[a] >= j)
            j = mp[a] + 1;
        ans = max(ans, i - j + 1);
        mp[a] = i;
    }
    cout << ans;
    return 0;
}