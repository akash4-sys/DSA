#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define int long long

const int MAX_VAL = 1e6;
int cnt[MAX_VAL + 1];

int32_t main()
{
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            ++cnt[a[i]];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += (cnt[a[i]] - 1) * (cnt[a[i]] - 2);
            for (int b = 2; a[i] * b * b <= MAX_VAL; ++b)
                ans += cnt[a[i] * b] * cnt[a[i] * b * b];
        }

        cout << ans << "\n";
        for (int i = 0; i < n; ++i)
            --cnt[a[i]];
    }
    return 0;
}