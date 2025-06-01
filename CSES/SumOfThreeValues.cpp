#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<vector<int>> v;
    for (int i = 0, a; i < n; i++)  {
        cin >> a;
        v.push_back({a, i + 1});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        for (int l = 0, r = n - 1; l < r;) {
            if (l != i && r != i && v[l][0] + v[r][0] == sum - v[i][0]) {
                cout << v[l][1] << " " << v[r][1] << " " << v[i][1];
                return 0;
            }
            if (v[l][0] + v[r][0] < sum - v[i][0])
                l++;
            else
                r--;
        }
    cout << "IMPOSSIBLE";
    return 0;
}