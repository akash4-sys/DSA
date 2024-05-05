#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ long long a; cin>>a; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

void storeFreq(vector<int> &a, map<int, int> &mp) {
    for (int i = 0, one = 0; i <= a.size(); i++) {
        if (a[i] == 0 && one)
            mp[one]++, one = 0;
        one += a[i];
    }
}

long long countRect(int n, int m, int k, int sq)
{
    long long cnt = 0;
    for (int f = 1; f <= sq; f++)
        if (k % f == 0)
        {
            long long len = f, width = k / f;
            cnt += max(n - len + 1, 0LL) * max(m - width + 1, 0LL);
            if (len != width)
                cnt += max(n - width + 1, 0LL) * max(m - len + 1, 0LL);
        }
    return cnt;
}

int main()
{
    fast;
    long long n = LL, m = LL, k = LL, ans = 0, sq = sqrtl(k);
    vector<int> a(n), b(m);
    iv(a);
    iv(b);
    a.emplace_back(0), b.emplace_back(0);

    map<int, int> amp, bmp;
    storeFreq(a, amp);
    storeFreq(b, bmp);

    for (auto &[l, c1] : amp)
        for (auto &[w, c2] : bmp)
            ans += (1LL * countRect(l, w, k, sq) * c1 * c2);

    cout << ans;
    return 0;
}