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
    int n = II, ans = 0;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        v[i] = II;
    
    function<int(int)> rec = [&](int i) -> int {
        int res = 0;
        for (int j = i * 2; j <= n; j += i)
            if (v[j] > v[i])
                res = max(res, rec(j) + 1);
        return res;
    };

    for (int i = 1; i <= n; i++)
        ans = max(ans, rec(i) + 1);
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