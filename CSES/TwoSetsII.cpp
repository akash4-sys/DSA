#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, mod = 1e9 + 7;
    cin >> n;
    int sum = n * (n + 1) / 2, x = sum / 2;
    if (sum % 2) {
        cout << 0;
        return 0;
    }

    vector<int> prev(x + 1, 0);
    prev[0] = 1;
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(x + 1);
        for (int j = 0; j <= x; j++)
           curr[j] = (prev[j] + (j >= i ? prev[j - i] : 0)) % mod;
        prev = curr;
    }
    cout << prev[x] << endl;
    return 0;
}