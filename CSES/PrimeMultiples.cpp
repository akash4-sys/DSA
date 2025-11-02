#include <bits/stdc++.h>
using namespace std;
#define LL ({ long long a; cin >> a ; a; })

int main()
{
    long long n = LL, m = LL, ans = 0;
    vector<long long> v(m);
    for (auto &p : v)
        p = LL;
    
    for (int mask = 1; mask < (1 << m); mask++) {
        long long cnt = n, bits = 0;
        for (int i = 0; i < m; i++)
            if (mask & (1 << i))
                cnt /= v[i], bits++;
        ans += (bits % 2 ? cnt : -cnt);
    }

    cout << ans;
    return 0;
}