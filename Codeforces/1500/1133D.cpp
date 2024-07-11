#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

int main()
{
    fast;
    int n = II, ans = 0, cnt = 0;
    vector<int> a(n), b(n);
    iv(a);
    iv(b);

    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)az
        if (a[i]) {
            int g = __gcd(a[i], b[i]);
            ans = max(ans, ++mp[{b[i] / g, a[i] / g}]);
        }
        else
            cnt += !b[i];
    cout << ans + cnt;
    return 0;
}