#include "../../headers.h"

class SegmentTree
{
    int n;
    vector<int> tree;

    int buildTree(vector<int> &v, int i, int left, int right)
    {
        if (left == right)
            return tree[i] = v[left];

        int mid = left + (right - left) / 2;
        int leftTree = buildTree(v, 2 * i, left, mid);
        int rightTree = buildTree(v, (2 * i) + 1, mid + 1, right);
        return tree[i] = leftTree + rightTree;
    }

public:
    SegmentTree(vector<int> &v)
    {
        n = v.size();
        tree = vector<int>(n * 4, 0);
        buildTree(v, 1, 0, n - 1);
    }

    int query(int left, int right, int i = 1, int tree_left = 0, int tree_right = -1)
    {
        if (left > right)
            return 0;
        if (tree_right == -1)
            tree_right = n - 1;
        if (tree_left > right || tree_right < left)
            return 0;
        if (tree_left >= left && tree_right <= right)
            return tree[i];

        int mid = tree_left + (tree_right - tree_left) / 2;
        int leftTree = query(left, right, 2 * i, tree_left, mid);
        int rightTree = query(left, right, 2 * i + 1, mid + 1, tree_right);
        return leftTree + rightTree;
    }

    void update(int idx, int val, int i = 1, int left = 0, int right = -1)
    {
        if (right == -1)
            right = n - 1;
        if (idx < left || idx > right)
            return;
        if (left == right) {
            tree[i] = val;
            return;
        }

        int mid = left + (right - left) / 2;
        update(idx, val, i * 2, left, mid);
        update(idx, val, (i * 2) + 1, mid + 1, right);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
};

class Solution
{
public:
    vector<int> countOfPeaks(vector<int> &v, vector<vector<int>> &qrs)
    {
        int n = v.size();
        vector<int> peaks(n, 0), ans;
        for (int i = 1; i < n - 1; i++)
            if (v[i] > v[i - 1] && v[i] > v[i + 1])
                peaks[i] = 1;
        
        SegmentTree tree(peaks);
        for (auto &q : qrs)
            if (q[0] == 1)
                ans.push_back(tree.query(q[1] + 1, q[2] - 1));
            else
            {
                int j = q[1];
                v[j] = q[2];
                for (int i = max(j - 1, 0); i < min(j + 2, n); i++)
                    if (i >= 1 && i + 1 < n && v[i] > v[i - 1] && v[i] > v[i + 1])
                        tree.update(i, 1);
                    else
                        tree.update(i, 0);
            }
        return ans;
    }
};