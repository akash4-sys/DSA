#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n - 2; i++)
            cout << i << " " << i << "\n";
        cout << n - 1 << " " << n << "\n";
        cout << n << " " << n << "\n";
    }
    return 0;
}