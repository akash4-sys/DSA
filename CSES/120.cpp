#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long

class PrefixSum
{
    vector<vector<int>> pf;
public:
    PrefixSum(vector<vector<int>> &m)
    {
        pf = vector<vector<int>>(m.size() + 1, vector<int>(m[0].size() + 1, 0));
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                pf[i + 1][j + 1] = (pf[i + 1][j] + pf[i][j + 1] + m[i][j]) - pf[i][j];
    }

    int sum(int x1, int y1, int x2, int y2)
    {
        int above = pf[x2 + 1][y1], left = pf[x1][y2 + 1], topLeft = pf[x1][y1];
        return pf[x2 + 1][y2 + 1] + topLeft - left - above;
    }
};

int main()
{
    int n, q, x1, y1, x2, y2;
    cin >> n >> q;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            m[i][j] = c == '*';
        }
    
    PrefixSum pf(m);
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pf.sum(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << endl;
    }
    return 0;
}