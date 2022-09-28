#include "../../headers.h"
// @lc app=leetcode id=2179 lang=cpp

class Solution
{
    int n, bit[100001] = {0};
    int query(int x, int sum = 0)
    {
        for(++x; x > 0; x -= (x & -x))
            sum += bit[x];
        return sum;
    }

    void update(int x, int val)
    {
        for(++x; x <= n + 2; x += (x & -x))
            bit[x] += val;
    }

public:
    long long goodTriplets(vector<int> &a, vector<int> &b)
    {
        long long ans = 0;
        n = a.size();
        vector<int> ids(n);
        for(int i = 0; i < n; i++)
            ids[b[i]] = i;
        for(int i = 0; i < n - 1; i++)
        {
            int mid = ids[a[i]], sm = query(mid), gr = n - 1 - mid - (i - sm);
            ans += (long long)sm * gr;
            update(mid, 1);
        }
        return ans;
    }
};

