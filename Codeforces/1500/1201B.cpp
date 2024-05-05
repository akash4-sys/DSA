#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II, x = 0, a;
    long long sum = 0;
    for (int i = 0; i < n; i++)
        a = II, x = max(x, a), sum += a;
    cout << (sum % 2 == 0 && sum - x >= x ? "YES" : "NO") << "\n";
    return 0;
}