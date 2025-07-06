#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &a : v)
        cin >> a;
    
    long long ans = 0;
    map<int, int> mp;
    for (int i = 0, j = 0; i < n; i++) {
        mp[v[i]]++;
        while (mp[v[i]] > 1)
            --mp[v[j++]];
        ans += i - j + 1;
    }
    cout << ans;
    return 0;
}