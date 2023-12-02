#include "../../headers.h"

#define ll long long

class BookMyShow
{
    int n, m;
    vector<vector<ll>> tree;

    vector<ll> build(int i, int l, int r)
    {
        if (l == r)
            return tree[i] = {m, m};

        ll tm = l + (r - l) / 2;
        auto left = build(i * 2, l, tm), right = build(i * 2 + 1, tm + 1, r);
        return tree[i] = {max(left[0], right[0]), left[1] + right[1]};
    }

    ll querySum(int qr, int i = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l > qr)
            return 0;
        if (r <= qr)
            return tree[i][1];
        
        int mid = (l + r) / 2;
        return querySum(qr, i * 2, l, mid) + querySum(qr, i * 2 + 1, mid + 1, r);
    }

    void reduceSum(int qr, int k, int i = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l > qr)
            return;
        if (l == r) {
            tree[i][0] -= k, tree[i][1] -= k;
            return;
        }

        int mid = (l + r) / 2;
        tree[i][1] -= k;
        if (mid + 1 > qr || tree[i * 2][1] >= k)
            reduceSum(qr, k, i * 2, l, mid);
        else
        {
            k -= tree[i * 2][1];
            reduceSum(qr, tree[i * 2][1], i * 2, l, mid);
            reduceSum(qr, k, i * 2 + 1, mid + 1, r);
        }
        tree[i][0] = max(tree[i * 2][0], tree[i * 2 + 1][0]);
    }

    vector<int> queryMax(int qr, int k, int i = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l > qr || tree[i][0] < k)
            return {};
        if (l == r)
            return {l, (int)(m - tree[i][0])};
        
        int mid = (l + r) / 2;
        auto res = queryMax(qr, k, i * 2, l, mid);
        return res.size() ? res : queryMax(qr, k, i * 2 + 1, mid + 1, r);
    }

    void updateMax(int idx, int k, int i = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (idx < l || idx > r)
            return;
        if (l == r) {
            tree[i][0] -= k, tree[i][1] -= k;
            return;
        }

        int mid = (l + r) / 2;
        tree[i][1] -= k;
        updateMax(idx, k, i * 2, l, mid);
        updateMax(idx, k, i * 2 + 1, mid + 1, r);
        tree[i][0] = max(tree[i * 2][0], tree[i * 2 + 1][0]);
    }

public:
    BookMyShow(int n, int m)
    {
        this->m = m, this->n = n;
        tree = vector(n * 4, vector<ll>(2, 0));
        build(1, 0, n - 1);
    }

    vector<int> gather(int k, int maxRow)
    {
        auto ans = queryMax(maxRow, k);
        if (ans.size())
            updateMax(ans[0], k);
        return ans;
    }

    bool scatter(int k, int maxRow)
    {
        ll sum = querySum(maxRow);
        if (sum >= k)
            reduceSum(maxRow, k);
        return sum >= k;
    }
};