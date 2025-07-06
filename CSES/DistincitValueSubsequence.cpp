#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        mp[a]++;
    }
    
    long long ans = 1, mod = 1e9 + 7;
    for (auto &it : mp)
        (ans *= (it.second + 1)) %= mod;
    cout << (ans + mod - 1) % mod;
    return 0;
}