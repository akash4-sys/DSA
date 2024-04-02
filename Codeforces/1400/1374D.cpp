#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl

ll solve()
{
    int n = II, k = II, c = 0, v = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a = II, r = k - (a % k);
        if (a % k == 0)
            continue;
        if (++mp[r] > c)
            c = mp[r], v = r;
        else if (mp[r] == c)
            v = max(v, r);
    }
    return max(1LL * k * (c - 1) + v + 1LL, 0LL);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}