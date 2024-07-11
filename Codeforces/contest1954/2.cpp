#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int solve()
{
    int n = II, j = -1, ans = n + 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = II;
    
    for (int i = 0; i < n; i++)
        if (a[i] != a[0])
            ans = min(ans, i - j - 1), j = i;
    ans = min(ans, n - j - 1);
    return ans == n ? -1 : ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}