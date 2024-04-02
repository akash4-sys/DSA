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
    int n = II, x = n + 1, y = n + 1, a, ans = 0;
    for (int i = 0; i < n; i++)
    {
        a = II;
        if (x > y) swap(x, y);
        if (a <= x)
            x = a;
        else if (a <= y)
            y = a;
        else
            x = a, ans++;
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