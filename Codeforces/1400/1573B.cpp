#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int solve()
{
    int n = II, ans = n * 2, j = ans;
    vector<int> v(ans);
    for (int i = 0; i < ans; i++)
        v[II - 1] = i % n;
    
    for (int i = 0; i < n * 2; i++)
        if (i % 2 == 0)
            j = min(j, v[i]);
        else
            ans = min(ans, v[i] + j);
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}