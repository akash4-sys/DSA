#include "../../headers.h"

// Iterative Segment Tree

class SegmentTree
{
    vector<int> t;
    int n;
public:
    SegmentTree(int _n): n(_n), t(2 * _n, 0) {}

    void update(int pos, int val)
    {
        pos += n;
        t[pos] = val;
        while (pos > 1)
            pos >>= 1, t[pos] = max(t[2 * pos], t[2 * pos + 1]);
    }

    int query(int low, int high)
    {
        low += n, high += n;
        int ans = 0;
        while (low < high)
        {
            if (low & 1)
                ans = max(ans, t[low++]);
            if (high & 1)
                ans = max(ans, t[--high]);
            low >>= 1;
            high >>= 1;
        }
        return ans;
    }
};

class Solution
{
public:
    int lengthOfLIS(vector<int> &v, int k)
    {
        int ans = 0;
        SegmentTree tree(100001);
        for (int i = 0; i < v.size(); i++)
        {
            int qres = tree.query(max(0, v[i] - k), v[i]) + 1;
            ans = max(ans, qres);
            tree.update(v[i], qres);
        }
        return ans;
    }
};



// Time Complexity - O(NK)
// Space Complexity - O(N)

class Solution
{
public:
    int lengthOfLIS(vector<int> &v, int k)
    {
        unordered_map<int, int> mp;
        for (auto n : v)
        {
            int x = 0;
            for (int i = 1; i <= k; i++)
                if(mp.count(n - i))
                    x = max(x, mp[n - i]);
            mp[n] = x + 1;
        }
        
        int ans = 0;
        for (auto [e, c] : mp)
            ans = max(ans, c);
        return ans;
    }
};