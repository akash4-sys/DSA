#include "../../headers.h"

class BIT
{
    vector<int> bit;
    int n;

public:
    BIT(int _n) : n(_n), bit(_n, 0) {}

    void update(int i, int val)
    {
        for (++i; i < n; i += i & (-i))
            bit[i] += val;
    }

    int getSum(int i)
    {
        int sum = 0;
        for (++i; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }
};

class Solution
{
    int binarySearch(vector<long> &v, int x)
    {
        int l = 0, r = v.size() - 1;
        while(l <= r) 
        {
            int mid = (l + r) / 2;
            if(v[mid] == x)
                return mid;
            if(v[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

public:
    int countRangeSum(vector<int> &v, int low, int high)
    {
        BIT bit(3 * (v.size() + 1) + 1);
        vector<long> sum(v.size() + 1), cand = {0, low - 1, high};
        sum[0] = 0;

        for (int i = 1; i <= v.size(); i++)
        {
            sum[i] = sum[i - 1] + v[i - 1];
            cand.push_back(sum[i]);
            cand.push_back(low + sum[i] - 1);
            cand.push_back(high + sum[i]);
        }
        cand.back() = LONG_MIN;
        
        sort(cand.begin(), cand.end());
        for (int i = 0; i <= v.size(); i++)
            bit.update(binarySearch(cand, sum[i]), 1);

        int ans = 0;
        for (int i = 0; i <= v.size() - 1; i++)
        {
            bit.update(binarySearch(cand, sum[i]), -1);
            ans -= bit.getSum(binarySearch(cand, low + sum[i] - 1));
            ans += bit.getSum(binarySearch(cand, high + sum[i]));
        }
        return ans;
    }
};

// @lc app=leetcode id=327 lang=cpp