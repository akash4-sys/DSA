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
    int a = II, b = II, c = II;
    if (c != a + 1)
        return -1;

    int h = a ? 32 - __builtin_clz(a) : 0;
    int padding = (1 << h) - a - 1;
    b -= min(b, padding);
    return h + ceil(b / (c * 1.0));
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}