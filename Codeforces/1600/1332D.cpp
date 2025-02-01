#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast;
    int k, n = 1;
    cin >> k;
    while (n <= k)
        n <<= 1;

    int x = (n << 1) - 1;
    int a[3][3] = {{x, k, k}, {n, k, 0}, {x, x, k}};
    cout << "3 3\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}