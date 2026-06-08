#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    int l = 1, r = n;
    for (int i = n - 1; i >= 0; i--)
        if (k >= i) {
            cout << r << " ";
            r--;
            k -= r;
        }
        else {
            cout << l << " ";
            l++;   
        }
    return 0;
}