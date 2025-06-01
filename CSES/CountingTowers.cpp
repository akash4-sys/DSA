#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9 + 7, N = 1e6 + 7, t, n;
    long long one[N], two[N];
    one[1] = two[1] = 1;
    for (int i = 2; i < N; i++) {
        one[i] = (one[i - 1] * 2 + two[i - 1]) % mod;
        two[i] = (two[i - 1] * 4 + one[i - 1]) % mod;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << (one[n] + two[n]) % mod << "\n";
    }
    return 0;
}