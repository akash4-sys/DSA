#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl

void solve()
{
    int n = II, x = II, l = 1, r = n + 1, idx = -1;
    vec a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = II;
        if (a[i] == x)
            idx = i;
    }
    
    while (r - l != 1)
    {
        int mid = (l + r) / 2;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid;
    }
    cout << "1\n" << idx << " " << l << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}