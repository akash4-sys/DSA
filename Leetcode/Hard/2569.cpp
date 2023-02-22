#include "../../headers.h"

// Lazy Segment Tree

class LazySegmentTree
{
    vector<int> t, lazy;
    int n;
    int build(vector<int> &v, int i, int l, int r)
    {
        if (l == r)
            return t[i] = v[l];
        int mid = l + (r - l) / 2;
        return t[i] = build(v, 2 * i, l, mid) + build(v, (2 * i) + 1, mid + 1, r);
    }

    void lazyValApply(int l, int r, int i)
    {
        if (!lazy[i])
            return;
        t[i] = (r - l + 1) - t[i];
        if (l != r)
            lazy[i * 2] ^= lazy[i], lazy[(i * 2) + 1] ^= lazy[i];
        lazy[i] = 0;
    }

    void updateUtil(int val, int st, int en, int i, int l, int r)
    {
        lazyValApply(l, r, i);
        if (l > r || l > en || r < st)
            return;

        if (l >= st && r <= en)
        {
            t[i] = (r - l + 1) - t[i];
            if (l != r)
                lazy[i * 2] ^= lazy[i], lazy[(i * 2) + 1] ^= lazy[i];
            return;
        }

        int mid = l + (r - l) / 2;
        updateUtil(val, st, en, i * 2, l, mid);
        updateUtil(val, st, en, i * 2 + 1, mid + 1, r);
        t[i] = t[i * 2] + t[i * 2 + 1];
    }

public:
    LazySegmentTree(vector<int> &v)
    {
        n = v.size();
        lazy = t = vector<int>(v.size() * 4, 0);
        build(v, 1, 0, v.size() - 1);
    }

    void update(int val, int l, int r)
    {
        updateUtil(val, l, r, 1, 0, n - 1);
    }

    int query()
    {
        return t[1];        // sum of entire arr
    }
};

class Solution
{
public:
    vector<long long> handleQuery(vector<int> &a, vector<int> &b, vector<vector<int>> &qrs)
    {
        vector<long long> ans;
        long long sum = accumulate(b.begin(), b.end(), 0LL);
        LazySegmentTree tree(a);

        for (auto &q : qrs)
        {
            if (q[0] == 1)
                tree.update(1, q[1], q[2]);
            else if (q[0] == 2)
                sum += (long long)tree.query() * q[1];
            else
                ans.push_back(sum);
        }
        return ans;
    }
};