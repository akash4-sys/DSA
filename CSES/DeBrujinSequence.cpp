#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string ans(n, '0');
    unordered_set<string> vis = {ans};
    for (int i = 0; i < (1 << n); i++) {
        string p = ans.substr(ans.size() - n + 1, n - 1);
        for (int j = 1; j >= 0; j--)
            if (string s = p + to_string(j); !vis.count(s)) {
                vis.insert(s);
                ans += to_string(j);
                break;
            }
    }
    cout << ans;
    return 0;
}