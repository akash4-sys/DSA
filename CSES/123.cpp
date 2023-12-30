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

    ll buildTree(vector<int> &v, int i, int left, int right)
    {
        if (left == right)
            return tree[i] = v[left];

        ll mid = left + (right - left) / 2;
        ll leftTree = buildTree(v, 2 * i, left, mid);
        ll rightTree = buildTree(v, (2 * i) + 1, mid + 1, right);
        return tree[i] = leftTree + rightTree;
    }

    ll treeSize(int n)
    {
        ll pow2 = 1;
        while (pow2 < n)
            pow2 = pow2 << 1;
        return 2 * pow2 - 1;
    }

public:
    SegmentTree(vector<int> &v)
    {
        n = treeSize(n);
        tree = vector<ll>(n, 0);
        buildTree(v, 1, 0, n / 2);
    }

    ll query(int left, int right, int i = 1, int tree_left = 0, int tree_right = -1)
    {
        if (tree_right == -1)
            tree_right = n / 2;
        if (tree_left > right || tree_right < left)
            return 0;
        if (tree_left >= left && tree_right <= right)
            return tree[i];

        ll mid = tree_left + (tree_right - tree_left) / 2;
        ll leftTree = query(left, right, 2 * i, tree_left, mid);
        ll rightTree = query(left, right, 2 * i + 1, mid + 1, tree_right);
        return leftTree + rightTree;
    }

    void update(ll idx, ll val, int i = 1, int left = 0, int right = -1)
    {
        if (right == -1)
            right = n / 2;
        if (idx < left || idx > right)
            return;
        if (left == right)
        {
            tree[i] = val;
            return;
        }

        ll mid = left + (right - left) / 2;
        update(idx, val, i * 2, left, mid);
        update(idx, val, (i * 2) + 1, mid + 1, right);
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
};

int calc(int l, int r, map<int, int> &salary_freq)
{
    int res = 0;
    for (auto it = salary_freq.lower_bound(l); it != salary_freq.end() && it->first <= r; it++)
        res += it->second;
    return res;
}

int bucketNum(int x)
{
    x -= x % 100 == 0;
    return x / 100;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> employee(n), buckets(1e7, 0);
    map<int, int> salary_freq;

    for (int i = 0; i < n; i++)
    {
        cin >> employee[i];
        salary_freq[employee[i]]++;
        buckets[bucketNum(employee[i])]++;
    }

    SegmentTree tree(buckets);
    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == '!')
        {
            int k, x;
            cin >> k >> x;
            int prev_salary = employee[k - 1];
            employee[k - 1] = x;

            int prev_bucket = bucketNum(prev_salary);
            int new_bucket = bucketNum(x);

            buckets[prev_bucket]--;
            buckets[new_bucket]++;
            salary_freq[prev_salary]--;
            salary_freq[x]++;

            tree.update(prev_bucket, buckets[prev_bucket]);
            tree.update(new_bucket, buckets[new_bucket]);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            int lbucket = bucketNum(a), rbucket = bucketNum(b);
            int ans = calc(a, min((lbucket + 1) * 100, b), salary_freq);
            ans += lbucket != rbucket ? calc(max(a, rbucket * 100 + 1), b, salary_freq) : 0;
            ans += tree.query(lbucket + 1, rbucket - 1);
            cout << ans << endl;
        }
    }
    return 0;
}