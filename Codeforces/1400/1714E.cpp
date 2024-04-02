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
    int n = II, zero_dig = 0, x = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = II;
        if (v[i] % 10 == 5)
            v[i] += 5;
        zero_dig += (v[i] % 10 == 0);
        x = max(x, v[i]);
    }

    if (zero_dig)
        return zero_dig == n && count(v.begin(), v.end(), x) == n ? "yes" : "no";
    
    for (; x % 10 != 2; x += (x % 10));
    for (int a : v)
        if (a != x)
        {
            for (; a % 10 != 2; a += (a % 10));
            if (abs(x - a) % 20 != 0)
                return "no";
        }
    return "yes";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}