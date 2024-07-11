#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << "\n"

bool f(int a, int b, int x, int x1, int x2)
{
    if (x2 - x1 == 0)
        return !(a || b);
    if (a >= b)
        return x - x1 >= a - b;
    return x2 - x >= b - a;
}

int solve()
{
    int a = II, b = II, c = II, d = II;
    int x = II, y = II, x1 = II, y1 = II, x2 = II, y2 = II;
    return f(a, b, x, x1, x2) && f(c, d, y, y1, y2);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}