#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl
#define iv(v) { for(auto &x : v) cin >> x; }

int solve()
{
    int n = II, x = II, y = II, ans = x - 2;
    vec a(x);
    iv(a);
    sort(all(a));

    if (n == 4)
        return x > 2 ? 2 : (a.back() - a[0] == 2 ? 2 : 0);
    
    for (int i = 1; i < x; i++)
        ans += (a[i] - a[i - 1] == 2);
    return ans + (n - a.back() + a[0] == 2);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}