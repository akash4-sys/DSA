#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl

long long solve()
{
    int n = II;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < n; i++)
        v[II]++;
    
    sort(all(v), greater<int>());
    long long ans = v[0], p = v[0];
    for (int i = 1; i < n; i++)
        p = max(min(p - 1, v[i] * 1LL), 0LL), ans += p;
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}