#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, x, y;
        cin >> a >> b;
        x = min(a, b), y = max(a, b);
        if (x * 2 < y)
        {
            cout << "NO\n";
            continue;
        }

        x -= (y / 2);
        y %= 2;
        if ((x == 1 && y == 2) || (x == 2 && y == 1) || (!x && !y))
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}