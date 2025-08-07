#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        int res = [&](this auto &&self, int n, int k) -> int {
            if (n == 1) return 1;
            if (k <= (n + 1) / 2) return (k * 2) % n;
            return self(n / 2, k - (n + 1) / 2) * 2 + (n % 2 ? 1 : -1);
        }(n, k);
        cout << res << "\n";
    }
    return 0;
}