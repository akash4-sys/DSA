#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
// read the solution, just need mobius function on this

int main()
{
    long long n;
    cin >> n;
    vector<int> a(N, 0);
    for (int i = 0, m; i < n; i++) {
        cin >> m;
        a[m]++;
    }

    long long ans = n * (n + 1) / 2;
    for (int i = 2; i < N; i++) {
        long long cnt = 0;
        for (int j = i; j < N; j += i)
            cnt += a[j];
        ans -= cnt * (cnt + 1) / 2;
    }
    cout << ans;
    return 0;
}