#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = {""};
    for (int i = 0; i < m; i++)
        ans[0] += (i % 2 ? "A" : "B");
    if (n > 1)
        ans.push_back(ans[0].substr(1) + "B");
    for (int i = 2; i < n; i++)
        ans.push_back(ans[i % 2]);

    char c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (ans[i][j] == c)
                ans[i][j] = ans[i][j] == 'A' ? 'C' : 'D';
        }

    for (auto &r : ans)
        cout << r << "\n";
    return 0;
}