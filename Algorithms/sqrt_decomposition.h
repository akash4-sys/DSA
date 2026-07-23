#pragma once

#include <vector>
using namespace std;

// range min query, range max query

// A compact implementation of the sparse table 
    class SparseTable {
        vector<vector<int>> mat;
        SparseTable(vector<int> &v) {
            int n = v.size();
            mat.push_back(v);
            for (int half_len = 1; half_len * 2 <= n; half_len *= 2) {
                auto &prev = mat.back();
                vector<int> cur;
                for (int i = 0; i + half_len < (int)prev.size(); i++)
                    cur.push_back(max(prev[i], prev[i + half_len]));
                mat.push_back(move(cur));
            }
        }

        int query(int l, int r) {
            int bits = log2(r - l + 1);
            return max(mat[bits][l], mat[bits][r - (1 << bits) + 1]);
        }
    };

class SparseTable
{
    int n, LOG = 18;
    vector<vector<int>> m;

public:
    SparseTable(vector<int> &v)
    {
        n = v.size();
        LOG = ceil(log2(n)) + 1;
        m = vector<vector<int>>(n, vector<int>(LOG, 0));

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