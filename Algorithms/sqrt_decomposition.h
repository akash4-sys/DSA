#pragma once

#include <vector>
using namespace std;

// range min query, range max query

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
                m[i][j] = max(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
    }

    int query(int l, int r)
    {
        int k = 0, len = r - l + 1;
        while ((1 << (k + 1)) <= len)
            k++;
        return max(m[l][k], m[r - (1 << k) + 1][k]);
    }
};