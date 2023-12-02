#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

class SparseTable
{
    int n, LOG = 18;
    vector<vector<int>> m;

public:
    SparseTable(vector<int> &v)
    {
        n = v.size();
        m = vector<vector<int>>(n + 1, vector<int>(LOG, 0));

        for (int i = 0; i < n; i++)
            m[i][0] = v[i];
        
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i + (1 << j) - 1 < n; i++)
                m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
    }

    int query(int l, int r)
    {
        int k = 0, len = r - l + 1;
        while ((1 << (k + 1)) <= len)       // nearest power of 2 to len
            k++;
        return min(m[l][k], m[r - (1 << k) + 1][k]);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    SparseTable mat(v);
    for (int i = 0, a, b; i < q; i++)
    {
        cin >> a >> b;
        cout << mat.query(a - 1, b - 1) << endl;
    }
    return 0;
}