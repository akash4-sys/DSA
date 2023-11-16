#include "../../headers.h"

#define ll long long

class Solution
{
public:
    long long maxBalancedSubsequenceSum(vector<int> &v)
    {
        map<int, long long> mp{{INT_MIN, 0}};
        for (int i = 0; i < v.size(); i++)
        {
            auto it = mp.upper_bound(v[i] - i);
            long long sum = v[i] + max(0LL, prev(it)->second);
            mp[v[i] - i] = sum;
            while (it != end(mp) && it->second <= sum)
                mp.erase(it++);
        }
        return mp.rbegin()->second;
    }
};


// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class BIT
{
    vector<ll> bit;
    int n;

public:
    BIT(int _n) : n(_n), bit(_n + 2, 0) {}

    ll maxSum(int i)
    {
        ll sum = 0;
        for (; i > 0; i -= i & (-i))
            sum = max(sum, bit[i]);
        return sum;
    }

    void update(int i, ll val)
    {
        for (i++; i < n; i += i & (-i))
            bit[i] = max(bit[i], val);
    }
};

class Solution
{
public:
    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        ll n = nums.size(), ans = LLONG_MIN;
        BIT tree(n);
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i] - i, i});

        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            ll sum = nums[v[i][1]] + tree.maxSum(v[i][1]);
            tree.update(v[i][1], sum);
            ans = max(ans, sum);
        }
        return ans;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class SegmentTree
{
    ll n;
    vector<ll> tree;

public:
    SegmentTree(int n)
    {
        this->n = n;
        tree.resize(4 * n, 0);
    }

    ll maxSum(int l, int r = -1, int i = 1, int tl = 0, int tr = -1)
    {
        if (tr == -1)
            tr = r = n - 1;
        if (tl > r || tr < l)
            return 0;
        if (tl >= l && tr <= r)
            return tree[i];

        int mid = (tl + tr) / 2;
        ll leftSum = maxSum(l, r, i * 2, tl, mid);
        ll rightSum = maxSum(l, r, i * 2 + 1, mid + 1, tr);
        return max(leftSum, rightSum);
    }

    void update(int pos, ll val, int i = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (pos < l || pos > r)
            return;
        if (l == r)
        {
            tree[i] = val;
            return;
        }

        int mid = (l + r) / 2;
        update(pos, val, i * 2, l, mid);
        update(pos, val, i * 2 + 1, mid + 1, r);
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
};

class Solution
{
public:
    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        int n = nums.size();
        SegmentTree seg(n);
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i] - i, i});

        sort(v.begin(), v.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[v[i][1]] = i;

        for (int i = n - 1; i >= 0; i--)
            seg.update(mp[i], seg.maxSum(mp[i]) + nums[i]);
        return seg.maxSum(0);
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
    long long n, dp[100001];
    long long rec(vector<int> &v, int i)
    {
        if (dp[i] != -1)
            return dp[i];

        long long res = 0;
        for (int j = i + 1; j < n; j++)
            if (v[j] - v[i] >= j - i)
                res = max(res, rec(v, j) + v[j]);
        return dp[i] = res;
    }

public:
    long long maxBalancedSubsequenceSum(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        n = v.size();
        long long ans = 0, neg = 0, mx = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(rec(v, i) + v[i], ans);
            neg += v[i] < 0;
            mx = max(mx, (long long)v[i]);
        }
        return neg == n ? mx : ans;
    }
};