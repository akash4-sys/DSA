#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

int main()
{
    fast;
    ll n = LL, m = LL, q = LL;
    while (q--)
    {
        ll sx = LL, sy = LL, ex = LL, ey = LL;
        int start = sx == 1 ? (sy > n / 2.0) : (sy > m / 2.0);
        int end = ex == 1 ? (ey > n / 2.0) : (ey > m / 2.0);

        if (n == m) {
            cout << (sy == ey ? "yes" : "no") << "\n";
            continue;
        }
        cout << (start == end ? "yes\n" : "no\n");
    }
    return 0;
}