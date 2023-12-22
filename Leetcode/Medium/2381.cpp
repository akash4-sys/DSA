#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &qrs)
    {
        int line[50001] = {0};
        for (auto &q : qrs)
            line[q[0]] += q[2] ? 1 : -1, line[q[1] + 1] += q[2] ? -1 : 1;
        
        for (int i = 0, val = 0; i < s.size(); i++)
        {
            val = (val + line[i]) % 26;
            s[i] = ((s[i] - 'a') + val + 26) % 26 + 'a';
        }
        return s;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N*4)

class LazySegmentTree
{
    int n;
    vector<int> tree, lazy;

public:
    LazySegmentTree(int n)
    {
        this->n = n;
        lazy = tree = vector<int>(n * 4, 0);
    }

    int query(int l, int r, int i = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1)
            tr = n - 1;
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return tree[i] + ((tr - tl + 1) * lazy[i]);

        int mid = (tl + tr) / 2;
        int queryLeft = query(l, min(r, mid), i * 2, tl, mid);
        int queryRight = query(max(l, mid + 1), r, i * 2 + 1, mid + 1, tr);
        return (r - l + 1) * lazy[i] + queryLeft + queryRight;
    }

    void update(int l, int r, int val, int i = 1, int tl = 0, int tr = -1)
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

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &qrs)
    {
        int n = s.size();
        LazySegmentTree tree(n);
        for (auto &q : qrs)
            q[2] ? tree.update(q[0], q[1], 1) : tree.update(q[0], q[1], -1);

        for (int i = 0; i < n; i++)
        {
            int val = tree.query(i, i), c = (s[i] - 'a') + val;
            s[i] = (c % 26 + 26) % 26 + 'a';
        }
        return s;
    }
};