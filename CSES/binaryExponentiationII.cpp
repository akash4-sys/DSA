#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, int mod)
{
    long long res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

/* Fermat's Little theorem states that all integer A not divisble by M satisfy
    pow(A, M - 1) % M == 1,
    that means every time b^c reaches m - 1 it turns to 1, i.e. you can take (b^c) % (mod - 1).
    => A * pow(A, M - 2) % M == 1
    => pow(A, M - 2) % M == 1 / A, (mod inverse)
*/

int main()
{
    int t, mod = 1e9 + 7;
    cin >> t;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << power(a, power(b, c, mod - 1), mod) << "\n";
    }
    return 0;
}