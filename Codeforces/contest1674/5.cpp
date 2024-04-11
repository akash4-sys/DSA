#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    int n = II;
    vector<int> v(n);
    for (int &k : v)
        k = II;
    
    int x = v[0], y = INT_MAX, ans = y;
    for (int i = 1; i < n; i++)
    {
        int a = v[i], b = v[i - 1];
        if (a < b)
            swap(a, b);
        
        if (i + 1 < n)
            ans = min(ans, (v[i - 1] + v[i + 1] + 1) / 2);

        int op = (a >= b * 2) ? (a + 1) / 2 : (a + b + 2) / 3;
        ans = min(ans, op);

        if (x > v[i])
            y = x, x = v[i];
        else if (y > v[i])
            y = v[i];
    }

    cout << min(ans, (x + 1) / 2 + (y + 1) / 2);
    return 0;
}