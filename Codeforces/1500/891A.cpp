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
    fast;
    int n = II, ones = 0, m = n + 1;
    vector<int> v(n);
    for (int &a : v)
        a = II, ones += (a == 1);
    
    if (ones) {
        cout << n - ones;
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1, g = v[i]; j < n; j++)
        {
            g = __gcd(g, v[j]);
            if (g == 1) {
                m = min(m, j - i);
                break;
            }
        }
    
    if (m == n + 1) {
        cout << -1;
        return 0;
    }

    cout << n + m - 1;
    return 0;
}