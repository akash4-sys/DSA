#include "headers.h"

// @ Binary Search on Segment Tree

#define ll long long

class SegmentTree
{
    ll n;
    vector<ll> tree;
public:

    SegmentTree(int _n) : n(_n) {
        tree.resize(4 * n, 0);
    }

    void update(int idx, ll val, int i = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1)
            tr = n - 1;
        if (idx < tl || idx > tr)
            return;
        if (tl == tr) {
            tree[i] += val;
            return;
        }

        ll mid = tl + (tr - tl) / 2;
        update(idx, val, i * 2, tl, mid);
        update(idx, val, (i * 2) + 1, mid + 1, tr);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    ll upper_bound(ll sum, int i = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1)
            tr = n - 1;
        if (tl == tr)
            return tree[i] >= sum ? tl : n;
        
        ll mid = tl + (tr - tl) / 2;
        if (tree[i * 2] >= sum)
            return upper_bound(sum, i * 2, tl, mid);
        return upper_bound(sum - tree[i * 2], i * 2 + 1, mid + 1, tr);
    }
};

class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &v, int k, int x)
    {
        vector<int> ans;
        SegmentTree tree(101);
        for (int i = 0; i < k - 1; i++)
            tree.update(v[i] + 50, 1);
        
        for (int i = k - 1; i < v.size(); i++)
        {
            tree.update(v[i] + 50, 1);
            ans.push_back(min(tree.upper_bound(x) - 50, 0LL));
            tree.update(v[i - k + 1] + 50, -1);
        }
        return ans;
    }
};



class Solution
{
    int xthSmallest(map<int, int> &mp, int x)
    {
        for (auto [n, c] : mp)
        {
            if (x - c <= 0)
                return min(0, n);
            x -= c;
        }
        return 99;
    }

public:
    vector<int> getSubarrayBeauty(vector<int> &v, int k, int x)
    {
        map<int, int> mp;
        for (int i = 0; i < k; i++)
            mp[v[i]]++;
        
        vector<int> ans = {xthSmallest(mp, x)};
        for (int i = 1; i <= v.size() - k; i++)
        {
            mp[v[i - 1]]--;
            if (!mp[v[i - 1]])
                mp.erase(v[i - 1]);
            mp[v[i + k - 1]]++;
            ans.push_back(xthSmallest(mp, x));
        }
        return ans;
    }
};