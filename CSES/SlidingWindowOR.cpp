#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k, x, A, B, C, res = 0;
    cin >> n >> k >> x >> A >> B >> C;
    vector<long long> a;
    vector<int> cnt(64, 0);
    for (int i = 0; i < n; i++)
    {
        a.push_back(x);
        int curr = 0;
        for (int j = 0; j < 64; j++)
        {
            if (i >= k) cnt[j] -= (a[i - k] & (1LL << j));
            cnt[j] += (x & (1LL << j));
            if (cnt[j]) curr |= 1LL << j;
        }
        if (i >= k - 1)
            res ^= curr;
        x = ((1LL * A * x) % C + B) % C;
    }
    cout << res;
    return 0;
}