#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// @ Index 1 of segment tree(lazy included) has sum of the entire arr

// Iterative
// lines that are marked with * are usually customized

class SegmentTree
{
    vector<int> t;
    int n;

public:
    SegmentTree(vector<int> &v)
    {
        n = v.size();
        t = vector<int>(n * 2, 0);
        for (int i = 0; i < n; i++)
            t[i + n] = v[i];
        for (int i = n - 1; i > 0; --i)
            t[i] = t[2 * i] + t[(2 * i) + 1];       // *
    }

    void update(int i, int val)
    {
        for (t[i += n] = val; i > 1;)
            t[i >>= 1] = t[2 * i] + t[(2 * i) + 1];          // *
    }

    int query(int l, int r)
    {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += t[l++];          // *
            if (r & 1)
                res += t[--r];          // *
        }
        return res;
    }
};



// Recursive
class SegmentTree
{
    vector<int> t;
    int n;
    int build(vector<int> &v, int i, int l, int r)
    {
        if (l == r)
            return t[i] = v[l];
        int mid = l + (r - l) / 2;
        return t[i] = build(v, 2 * i, l, mid) + build(v, (2 * i) + 1, mid + 1, r);
    }

    void updateUtil(int pos, int val, int i, int l, int r)
    {
        if (pos < l || pos > r)
            return;
        if (l == r)
        {
            t[i] += val;
            return;
        }

        int mid = l + (r - l) / 2;
        updateUtil(pos, val, i * 2, l, mid);
        updateUtil(pos, val, (i * 2) + 1, mid + 1, r);
        t[i] = t[i * 2] + t[(i * 2) + 1];
    }

    int queryUtil(int st, int en, int i, int l, int r)
    {
        if (l > en || r < st)
            return 0;
        if (l >= st && r <= en)
            return t[i];
        int mid = l + (r - l) / 2;
        return queryUtil(st, en, i * 2, l, mid) + queryUtil(st, en, (i * 2) + 1, mid + 1, r);
    }

public:
    SegmentTree(vector<int> &v)
    {
        n = v.size();
        t = vector<int>(v.size() * 4, 0);
        build(v, 1, 0, v.size() - 1);
    }

    void update(int pos, int val)
    {
        updateUtil(pos, val, 1, 0, n - 1);
    }

    int query(int l, int r)
    {
        return queryUtil(l, r, 1, 0, n - 1);
    }
};