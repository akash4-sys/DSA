#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

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

int main()
{
    ll n, q, type, idx, val, l, r;
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    
    LazySegmentTree tree(v);
    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> l >> r >> val;
            tree.update(l - 1, r - 1, val);
        }
        else
        {
            cin >> idx;
            cout << tree.query(idx - 1, idx - 1) << endl;
        }
    }
    return 0;
}