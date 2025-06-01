#include <bits/stdc++.h>
using namespace std;

#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << endl;}

int main()
{
    int n, ans = 0, end = 0;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2, 0));
    for (auto &r : v)
        cin >> r[0] >> r[1];
    sort(v.begin(), v.end(), [&](auto &a, auto &b){
        return a[1] < b[1];
    });

    for (auto &r : v)
        if (r[0] >= end) {
            ans++;
            end = r[1];
        }
    cout << ans;
    return 0;
}