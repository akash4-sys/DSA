#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    long long n;
    cin >> n;
    long long sum = (n * (n + 1)) / 2, x = sum / 2, i = n;
    if (sum % 2) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<int> v;
    while (x - i >= 0)
        x -= i, v.push_back(i--);
    
    if (x > 0)
        v.push_back(x);
    cout << v.size() << "\n";
    for (int a : v)
        cout << a << " ";
    
    cout << "\n" << n - v.size() << "\n";
    for (int j = 1; j <= i; j++)
        if (j != x)
            cout << j << " ";
    return 0;
}