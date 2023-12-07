#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long

class SegmentTree
{
    ll n;
    vector<ll> tree;

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
    SegmentTree(vector<ll> &v)
    {
        n = v.size();
        tree = vector<ll>(n * 4, 0);
        buildTree(v, 1, 0, n - 1);
    }

    ll query(int left, int right, int i = 1, int tree_left = 0, int tree_right = -1)
    {
        if (tree_right == -1)
            tree_right = n - 1;
        if (tree_left > right || tree_right < left)
            return 0;
        if (tree_left >= left && tree_right <= right)
            return tree[i];

        ll mid = tree_left + (tree_right - tree_left) / 2;
        ll leftTree = query(left, right, 2 * i, tree_left, mid);
        ll rightTree = query(left, right, 2 * i + 1, mid + 1, tree_right);
        return leftTree + rightTree;
    }

    void update(int idx, ll val, int i = 1, int left = 0, int right = -1)
    {
        if (right == -1)
            right = n - 1;
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
};


int main()
{
    ll n, q, type, idx, val, l, r;
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    SegmentTree tree(v);
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> idx >> val;
            tree.update(idx - 1, val);
        }
        else
        {
            cin >> l >> r;
            cout << tree.query(l - 1, r - 1) << endl;
        }
    }
    return 0;
}