#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ long long a; cin>>a; a; })

string solve()
{
    long long n = LL, x = LL, y = LL;
    while (n--)
        x += LL;
    return (x % 2 == 0) == (y % 2 == 0) ? "Alice" : "Bob";
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}