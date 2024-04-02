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
    int n = II;
    vector<vector<long long>> v(2, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        v[0][i] = II;
    for (int i = 0; i < n; i++)
        v[1][i] = II;
    
    long long a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        long long c = max(a, b + v[0][i]), d = max(a + v[1][i], b);
        a = c, b = d;
    }
    
    cout << max(a, b);
    return 0;
}