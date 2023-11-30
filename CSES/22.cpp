#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    for (int i = 0, j = n - 1; i <= j; j--, ans++)
        if (v[i] + v[j] <= x)
            i++;
        
    cout << ans;
    return 0;
}