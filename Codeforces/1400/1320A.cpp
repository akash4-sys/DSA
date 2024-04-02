#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast;
    long long n, b, ans = 0;
    cin >> n;
    map<long long, long long> mp;
    for (int i = 1; i <= n; i++) {
        cin >> b;
        mp[b - i] += b;
    }

    for (auto it : mp)
        ans = max(ans, it.second);
    cout << ans;
    return 0;
}