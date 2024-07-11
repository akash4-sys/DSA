#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

int main()
{
    fast;
    int t = LL;
    while (t--)
    {
        ll n = LL, sum = 0;
        for (ll i = 1; n >= i; i *= 2)
            sum += (n / i);
        cout << sum << endl;
    }
    return 0;
}