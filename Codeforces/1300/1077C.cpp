#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    long long n, sum = 0;
    cin >> n;
    map<long long, int> mp;
    vector<long long> v(n), ans;
    for (auto &a : v) {
        cin >> a;
        sum += a;
        mp[a]++;
    }
    
    for (int i = 0; i < n; i++)
        if ((sum - v[i]) % 2 == 0) {
            long long x = (sum - v[i]) / 2;
            if (mp.count(x) && (v[i] != x || mp[x] > 1))
                ans.push_back(i + 1);
        }
    
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    return 0;
}