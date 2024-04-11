#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

void solve()
{
    ll n = LL, k = LL;
    if (k > n)
        cout << "NO\n";
    else if (k == 1)
        cout << "YES\n1\n" << n << "\n";
    else if (n == k)
        cout << "YES\n1\n1\n";
    else if (n >= k * 2 - 1)
        cout << "YES\n2\n" << n - k + 1 << " 1\n";
    else
        cout << "NO\n";
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        solve();
    return 0;
}