#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    ll n = LL, ans = 0;
    vector<int> a(n);
    iv(a);
    map<vector<int>, ll> mp;
    for (int i = 0; i < n - 2; i++)
    {
        vector<int> key = {a[i], a[i + 1], a[i + 2]};
        vector<vector<int>> keys = {{a[i], a[i + 1], 0}, {0, a[i + 1], a[i + 2]}, {a[i], 0, a[i + 2]}};
        for (auto &k : keys)
            ans += mp[k] - mp[key], mp[k]++;
        mp[key]++;
    }
    return ans;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}