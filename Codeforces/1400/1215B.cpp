#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "

int main()
{
    fast;
    ll n = LL, odd = 0, even = 0, pos = 0;
    vec v(n);
    for (ll &a : v)
        a = LL > 0 ? 0 : 1;
    
    for (ll &a : v)
    {
        if (a)
            swap(odd, even), odd++;
        else
            even++;
        pos += even;
    }
    
    ll m = n * (n + 1) / 2;
    pf(m - pos) << pos << "\n";
    return 0;
}