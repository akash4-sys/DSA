#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// @ lazy segment tree can be used to update data over a range
// vector lazy stores pending updates

#define ll long long

class LazySegmentTree
{
    ll n;
    vector<ll> tree, lazy;

    ll buildTree(vector<ll> &v, int i, int left, int right)
    {
        if (left == right)
            return tree[i] = v[left];

        ll mid = left + (right - left) / 2;
        ll leftTree = buildTree(v, 2 * i, left, mid);
        ll rightTree = buildTree(v, (2 * i) + 1, mid + 1, right);
        return tree[i] = leftTree + rightTree;
    }

public:
    LazySegmentTree(vector<ll> &v)
    {
        n = v.size();
        lazy = tree = vector<ll>(n * 4, 0);
        buildTree(v, 1, 0, n - 1);
    }

    ll query(int l, int r, int i = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1) 
            tr = n - 1;
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return tree[i] + ((tr - tl + 1LL) * lazy[i]);

        int mid = (tl + tr) / 2;
        ll queryLeft = query(l, min(r, mid), i * 2, tl, mid);
        ll queryRight = query(max(l, mid + 1), r, i * 2 + 1, mid + 1, tr);
        return (r - l + 1LL) * lazy[i] + queryLeft + queryRight;
    }

    void update(int l, int r, int val = 1, int i = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1) 
            tr = n - 1;
        if (l == tl && r == tr)
            lazy[i] += val;
        else if (l <= r)
        {
            lazy[i * 2] += lazy[i];
            lazy[i * 2 + 1] += lazy[i];
            lazy[i] = 0;
            int mid = (tl + tr) / 2;
            update(l, min(r, mid), val, i * 2, tl, mid);
            update(max(l, mid + 1), r, val, i * 2 + 1, mid + 1, tr);
            tree[i] = query(tl, mid, i * 2, tl, mid) + query(mid + 1, tr, i * 2 + 1, mid + 1, tr);
        }
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