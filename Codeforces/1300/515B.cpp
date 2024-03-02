#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define all(v) v.begin(), v.end()
#define II ({ int a; cin>>a; a; })

int main()
{
    int n = II, m = II;
    vector<int> boys(n, 0), girls(m, 0);
    for (int i = 0, hb = II; i < hb; i++)
        boys[II] = 1;
    for (int i = 0, hg = II; i < hg; i++)
        girls[II] = 1;
    
    int mx = (min(n, m) + 1) * (max(n, m) - 1);
    for (int day = 0; day <= mx; day++)
        if (boys[day % n] || girls[day % m])
            boys[day % n] = girls[day % m] = 1;
    
    if (accumulate(all(boys), 0) == n && accumulate(all(girls), 0) == m) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}