#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, k, j = 0, cnt = 0;
    cin >> n >> k;
 
    long long ans = 0;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cnt += (mp[v[i]]++ == 0);
        for (; cnt > k; j++)
            if (--mp[v[j]] == 0)
                cnt--;
        ans += i - j + 1;
    }
    cout << ans;
    return 0;
}