#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &t : v)
        cin >> t;
    sort(v.begin(), v.end());

    long long ans = 0, time = 0, l = 0, r = n - 1;
    while (l <= r)
        if (v[l] <= time)
            time -= v[l++];
        else
            time += v[r], ans += v[r--];
    cout << (ans * 2) - (l + 1 < n ? time : 0);
    return 0;
}