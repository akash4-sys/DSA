#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

long long solve()
{
    int n = II;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        x[i] = II, y[i] = II;
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long d1 = x[n / 2] - x[(n - 1) / 2] + 1;
    long long d2 = y[n / 2] - y[(n - 1) / 2] + 1;
    return d1 * d2;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}