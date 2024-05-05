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
    int n = II;
    vector<int> v(n * 2);
    for (int &a : v)
        a = II;
    sort(v.begin(), v.end());
    
    if (v[n] == v[n - 1])
        cout << "NO";
    else
        cout << "YES";
    return 0;
}