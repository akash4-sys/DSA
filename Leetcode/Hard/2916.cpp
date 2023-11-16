#include "../../headers.h"

// Lazy Segment tree
// Query and Update function is classic implementation

class Solution
{
    int tree[400000] = {}, lazy[400000] = {}, last[100001] = {}, mod = 1e9 + 7;

    long long query(int l, int r, int i = 1, int tl = 0, int tr = 1e5)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return (tree[i] + ((tr - tl + 1LL) * lazy[i])) % mod;

        int mid = (tl + tr) / 2;
        long long queryLeft = query(l, min(r, mid), i * 2, tl, mid);
        long long queryRight = query(max(l, mid + 1), r, i * 2 + 1, mid + 1, tr);
        return (r - l + 1LL) * lazy[i] + queryLeft + queryRight;
    }

    void update(int l, int r, int val = 1, int i = 1, int tl = 0, int tr = 1e5)
    {
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

public:
    int sumCounts(vector<int> &v)
    {
        long long ans = 0, sum_sq = 0;
        for (int r = 0; r < v.size(); r++)
        {
            int l = last[v[r]];
            long long sum = query(l, r);
            update(l, r);
            (sum_sq += (2 * sum) + (r - l + 1)) %= mod;
            (ans += sum_sq) %= mod;
            last[v[r]] = r + 1;
        }
        return ans;
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int sumCounts(vector<int> &v)
    {
        long long cnt[100001] = {0}, last[100001] = {0}, mod = 1e9 + 7, ans = 0, sum_sq = 0;
        for (int r = 0; r < v.size(); r++)
        {
            int l = last[v[r]];
            long long sum = accumulate(begin(cnt) + l, begin(cnt) + r, 0LL);
            transform(begin(cnt) + l, begin(cnt) + r + 1, begin(cnt) + l, [](int c){
                return ++c;
            });
            (sum_sq += (2 * sum) + (r - l + 1)) %= mod;
            (ans += sum_sq) %= mod;
            last[v[r]] = r + 1;
        }
        return ans;
    }
};