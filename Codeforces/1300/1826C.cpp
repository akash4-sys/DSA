#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

string solve()
{
    int n = II, m = II;
    if (m == 1 || n == 1)
        return "YES";
    if (n % 2 == 0 || n < m || n % m == 0)
        return "NO";
    
    for (int i = 3, sq = sqrt(n); i <= min(sq, m); i++)
        if (n % i == 0)
            return "NO";
    return "YES";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << endl;
    return 0;
}