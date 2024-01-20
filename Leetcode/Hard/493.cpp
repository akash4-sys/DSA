#include "../../headers.h"

class BIT
{
    vector<int> bit;
    int n;

public:
    BIT(int _n): n(_n), bit(_n, 0) {}

    int getSum(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    void update(int i) {
        for (i++; i < n; i += i & (-i))
            bit[i]++;
    }
};

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        BIT bit(v.size() + 1);

        int ans = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            ans += bit.getSum(lower_bound(v.begin(), v.end(), ceil(nums[i] / 2.0)) - v.begin());
            bit.update(lower_bound(v.begin(), v.end(), nums[i]) - v.begin());
        }
        return ans;
    }
};


// Time Complexity - O(NlogN)
// Space Complexity - O(N);

class Solution
{
    int mergeSort(auto begin, auto end)
    {
        if (end - begin <= 1)
            return 0;
        
        auto mid = begin + (end - begin) / 2;
        int count = mergeSort(begin, mid) + mergeSort(mid, end);
        for (auto i = begin, j = mid; i != mid; i++) {
            for (; j != end && *i > 2LL * (*j); j++);
            count += j - mid;
        }

        inplace_merge(begin, mid, end);
        return count;
    }

public:
    int reversePairs(vector<int> &v) {
        return mergeSort(v.begin(), v.end());
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N);

class Solution
{
    int count = 0;

    void outPlaceMerge(vector<int> &v, int low, int mid, int high)
    {
        if (low >= high)
            return;
        int l = low, r = mid + 1, k = 0, size = high - low + 1;

        // Counting pairs in both subarrays during merge
        for (int i = low, j = mid + 1; i <= mid; i++)
        {
            while (j <= high && v[i] > 2LL * v[j])
                j++;
            count += (j - mid - 1);
        }

        vector<int> sorted(size, 0);
        while (l <= mid and r <= high)
            sorted[k++] = v[l] < v[r] ? v[l++] : v[r++];
        while (l <= mid)
            sorted[k++] = v[l++];
        while (r <= high)
            sorted[k++] = v[r++];
        for (int i = 0; i < size; i++)
            v[i + low] = sorted[i];
    }

    void mergeSort(vector<int> &v, int low, int high)
    {
        if (low >= high)
            return;
        int mid = low + ((high - low) / 2);
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        outPlaceMerge(v, low, mid, high);
    }

public:
    int reversePairs(vector<int> &v)
    {
        mergeSort(v, 0, v.size() - 1);
        return count;
    }
};