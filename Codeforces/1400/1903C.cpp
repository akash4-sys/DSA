

#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

// Problem is very tough, it's underrated a same is copy is 1900 rated
// Reached at this concusion but code was too complicated so ended up thinking its wrong

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        ll n = II, sum = 0, ans = 0;
        vector<ll> v(n);
        for (int i = 0; i < n; i++)
            v[i] = II;
        
        for (int i = n - 1; i > 0; i--) {
            sum += v[i];
            ans += (sum >= 0) ? sum : 0;
        }
        cout << ans + sum + v[0] << "\n";
    }
    return 0;
}