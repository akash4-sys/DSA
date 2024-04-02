#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl

int solve()
{
    int n = II, k = II, bug_at = -1;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = II;
    
    for (int i = 1; i <= k; i++)
        if (v[i] * 2 <= v[i - 1])
            bug_at = i;
    
    int ans = bug_at == -1;
    for (int i = 1; i < n - k; i++)
    {
        if (v[i + k] * 2 <= v[i + k - 1])
            bug_at = i + k;
        ans += !(i < bug_at && bug_at <= i + k);
    }
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