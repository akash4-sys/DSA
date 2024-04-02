#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

ll solve()
{
    int n = II, m = II, a = n + 1;
    vector<int> v(n + 1, n + 1), pf(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x = II, y = II;
        if (x > y)
            swap(x, y);
        v[x] = min(v[x], y);
    }

    ll ans = 0;
    for (int i = n; i > 0; i--) {
        a = min(a, v[i]);
        ans += (a - (n - i + 1));
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}