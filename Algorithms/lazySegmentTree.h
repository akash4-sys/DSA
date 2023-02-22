#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// @ lazy segment tree can be used to update data over a range
// vector lazy stores pending updates

// recursive

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
        t[i] += (r - l + 1) * lazy[i];
        if (l != r)
            lazy[i * 2] += lazy[i], lazy[(i * 2) + 1] += lazy[i];
        lazy[i] = 0;
    }

    void updateUtil(int val, int st, int en, int i, int l, int r)
    {
        lazyValApply(l, r, i);
        if (l > r || l > en || r < st)
            return;

        if (l >= st && r <= en)
        {
            t[i] += (r - l + 1) * val;
            if (l != r)
                lazy[i * 2] += lazy[i], lazy[(i * 2) + 1] += lazy[i];
            return;
        }

        int mid = l + (r - l) / 2;
        updateUtil(val, st, en, i * 2, l, mid);
        updateUtil(val, st, en, i * 2 + 1, mid + 1, r);
        t[i] = t[i * 2] + t[i * 2 + 1];
    }

    int queryUtil(int st, int en, int i, int l, int r)
    {
        if (l > en || r < st)
            return 0;
        lazyValApply(l, r, i);
        if (l >= st && r <= en)
            return t[i];
        int mid = l + (r - l) / 2;
        return queryUtil(st, en, i * 2, l, mid) + queryUtil(st, en, (i * 2) + 1, mid + 1, r);
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

    int query(int l, int r)
    {
        return queryUtil(l, r, 1, 0, n - 1);
    }
};


// iterative

class LazySegmentTree
{
    int h, n;
    vector<int> lazy, t;

    void calc(int p, int k)
    {
        if (lazy[p])
            t[p] = t[2 * p] + t[(2 * p) + 1];
        else
            t[p] = lazy[p] * k;
    }

    void apply(int p, int val, int k)
    {
        t[p] += val * k;
        if (p < n)
            lazy[p] += val;
    }

    void build(int l, int r)
    {
        l += n, r += n - 1;
        for (int k = 2; l > 1; k <<= 1)
        {
            l >>= 1, r >>= 1;
            for (int i = r; i >= l; --i)
                calc(i, k);
        }
    }

    void push(int l, int r)
    {
        int s = h, k = 1 << (h - 1);
        for (l += n, r += n - 1; s > 0; --s, k >>= 1)
            for (int i = l >> s; i <= r >> s; ++i)
                if (lazy[i])
                {
                    apply(i * 2, lazy[i], k);
                    apply((i * 2) + 1, lazy[i], k);
                    lazy[i] = 0;
                }
    }

public:
    LazySegmentTree(vector<int> &v)
    {
        n = v.size();
        t = lazy = vector<int>(n * 2, 0);
        h = sizeof(int) * 8 - __builtin_clz(n);

        for (int i = 0; i < n; i++)
            t[i + n] = v[i];
        for (int i = n - 1; i > 0; --i)
            t[i] = t[2 * i] + t[(2 * i) + 1];
    }

    void update(int l, int r, int val)
    {
        push(l, l + 1);
        push(r - 1, r);
        int l1 = l, r1 = r, k = 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1)
        {
            if (l & 1)
                apply(l++, val, k);
            if (r & 1)
                apply(--r, val, k);
        }
        build(l1, l1 + 1);
        build(r1 - 1, r);
    }

    int query(int l, int r)
    {
        push(l, l + 1);
        push(r - 1, r);
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += t[l++];
            if (r & 1)
                res += t[--r];
        }
        return res;
    }
};