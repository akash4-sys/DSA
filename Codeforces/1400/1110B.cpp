#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast;
    int n, m, k, p, c;
    cin >> n >> m >> k >> p;
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> c;
        d[i] = c - p;
        p = c;
    }
    
    sort(d.begin(), d.end());
    cout << accumulate(d.begin(), d.end() - k + 1, 0LL) + k;
    return 0;
}