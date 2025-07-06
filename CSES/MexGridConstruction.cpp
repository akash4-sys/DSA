#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, -1));
    vector<set<int>> col(n);
    for (int i = 0; i < n; i++) 
        ans[0][i] = i, col[i].insert(i);
    
    for (int i = 1; i < n; i++)
    {
        set<int> row;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n * 2; k++)
                if (row.find(k) == row.end() && col[j].find(k) == col[j].end()) {
                    ans[i][j] = k;
                    row.insert(k);
                    col[j].insert(k);
                    break;
                }
    }

    for (auto &r: ans) {
        for (int &a : r)
            cout << a << " ";
        cout << "\n";
    }
    return 0;
}