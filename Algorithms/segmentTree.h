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
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int> &v)
    {
        n = v.size();
        tree = vector<int>(n * 2, 0);
        for (int i = 0; i < n; i++)
            tree[i + n] = v[i];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[2 * i] + tree[(2 * i) + 1];       // *
    }

    void update(int i, int val)
    {
        for (tree[i += n] = val; i > 1;)
            tree[i >>= 1] = tree[2 * i] + tree[(2 * i) + 1];          // *
    }

    int query(int left, int right)
    {
        int res = 0;
        for (left += n, right += n + 1; left < right; left >>= 1, right >>= 1)
        {
            if (left & 1)
                res += tree[left++];          // *
            if (right & 1)
                res += tree[--right];          // *
        }
        return res;
    }
};



// Recursive segment tree is more general

#define ll long long

class SegmentTree
{
    ll n;
    vector<ll> tree;

    ll buildTree(vector<int> &v, int i, int left, int right)
    {
        if (left == right)
            return tree[i] = v[left];

        ll mid = left + (right - left) / 2;
        ll leftTree = buildTree(v, 2 * i, left, mid);
        ll rightTree = buildTree(v, (2 * i) + 1, mid + 1, right);
        return tree[i] = leftTree + rightTree;
    }

    ll query(int left, int right, int i, int tree_left, int tree_right)
    {
        if (tree_left > right || tree_right < left)
            return 0;
        if (tree_left >= left && tree_right <= right)
            return tree[i];

        ll mid = tree_left + (tree_right - tree_left) / 2;
        ll leftTree = query(left, right, 2 * i, tree_left, mid);
        ll rightTree = query(left, right, 2 * i + 1, mid + 1, tree_right);
        return leftTree + rightTree;
    }

    void update(int idx, int val, int i, int left, int right)
    {
        if (idx < left || idx > right)
            return;

        if (left == right) {
            tree[i] = val;
            return;
        }

        ll mid = left + (right - left) / 2;
        update(idx, val, i * 2, left, mid);
        update(idx, val, (i * 2) + 1, mid + 1, right);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

public:
    SegmentTree(vector<int> &v)
    {
        n = v.size();
        tree = vector<ll>(n * 4, 0);
        buildTree(v, 1, 0, v.size() - 1);
    }

    void update(int idx, int val) {
        return update(idx, val, 1, 0, n - 1);
    }

    ll query(int left, int right) {
        return query (left, right, 1, 0, n - 1);
    }
};