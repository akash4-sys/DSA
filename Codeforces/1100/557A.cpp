#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

void solve()
{
    int n = II, fmin = II, fmax = II, smin = II, smax = II;
    int tmin = II, tmax = II;

    n -= fmin + smin + tmin;
    cout << fmin + min(fmax - fmin, n) << ' ';
    n -= min(fmax - fmin, n);
    cout << smin + min(smax - smin, n) << ' ';
    n -= min(smax - smin, n);
    cout << tmin + min(tmax - tmin, n) << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}