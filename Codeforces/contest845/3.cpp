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
    int n = II, c = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[II]++, mp[II + 1]--;
    
    for (auto &[time, cnt] : mp) {
        c += cnt;
        if (c > 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}