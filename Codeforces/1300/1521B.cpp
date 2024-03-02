#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define II ({ int a; cin>>a; a; })

int main()
{
    int tc = II;
    while (tc--)
    {
        int n = II, x = INT_MAX, j = 0;
        for (int i = 1; i <= n; i++) {
            int a = II;
            if (a < x)
                x = a, j = i;
        }

        cout << n - 1 << endl;
        for (int i = 1; i <= n; i++)
            if (i != j)
                cout << i << " " << j << " " << x + abs(i - j) << " " << x << "\n";
    }
    return 0;
}