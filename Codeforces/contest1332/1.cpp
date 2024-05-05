#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl

bool solve()
{
    int a = II, b = II, c = II, d = II;
    int x = II, y = II, x1 = II, y1 = II, x2 = II, y2 = II;
    x += b - a;
    y += d - c;
    int xx = x1 <= x && x <= x2 && (x2 > x1 || a + b == 0);
    int yy = y1 <= y && y <= y2 && (y2 > y1 || c + d == 0);
    return xx && yy;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}