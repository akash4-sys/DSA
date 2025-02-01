#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast;
    int t, mod = 1e9 + 7;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll i = 0, a = 0, b = 1 % k;
        do {
            tie(a, b) = pair(b, (a + b) % k);
            i++;
        } while (a);
        cout << i * (n % mod) % mod << "\n";
    }
    return 0;
}