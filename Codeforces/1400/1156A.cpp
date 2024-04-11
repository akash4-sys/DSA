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
    int n = II, ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = II;
        ans += (v[i] != 1 ? v[i] * 2 + 2 : 0);
    }

    for (int i = 1; i < n; i++) {
        if (v[i] + v[i - 1] == 5) {
            cout << "Infinite";
            return 0;
        }
        ans -= (i >= 2 && v[i] == 2 && v[i - 2] == 3);
    }

    ans -= (v[0] != 1 ? v[0] + 1: 0) + (v.back() != 1 ? v.back() + 1: 0);
    cout << "Finite\n" << ans;
    return 0;
}