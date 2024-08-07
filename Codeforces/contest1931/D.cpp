#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

long long solve()
{
    long long ans = 0;
    int n = II, x = II, y = II;
    map<pair<int, int>, long long> mp;
    for (int i = 0; i < n; i++)
    {
        int a = II, xc = (x - (a % x)) % x;
        ans += mp[{a % x, a % y}];
        mp[{xc, a % y}]++;
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