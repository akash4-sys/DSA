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
    int n = II, fq = 0, cnt = 0;
    vector<int> a(n), b(n);
    for (int &x : a)
        x = II;
    for (int &x : b)
        x = II;
    
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
        if (!a[i])
            cnt += !b[i];
        else
        {
            b[i] *= -1;
            if (b[i] < 0)
                b[i] *= -1, a[i] *= -1;
            else if (!b[i] && a[i] < 0)
                a[i] *= -1;
            
            int g = __gcd(abs(a[i]), abs(b[i]));
            fq = max(fq, ++mp[{b[i] / g, a[i] / g}]);
        }
    cout << fq + cnt;
    return 0;
}