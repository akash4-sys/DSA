#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    int n, m, k, s, ans = 0;
    cin >> n >> m >> k;
    multiset<int> a, b;
    for (int i = 0; i < n; i++)
        cin >> s, a.insert(s);
    for (int i = 0; i < m; i++)
        cin >> s, b.insert(s);
    
    for (auto &x : a)
        if (auto it = b.lower_bound(max(x - k, 0)); it != b.end() && *it <= x + k)
            ans++, b.erase(it);
            
    cout << ans << endl;
    return 0;
}