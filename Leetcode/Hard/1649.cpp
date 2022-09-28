#include "../../headers.h"
// @lc app=leetcode id=1649 lang=cpp

// Binary Indexed Tree
// Time Complexity - O(NlogK)
// Space Complexity - O(N)

// A bit modified Binary Indexed Tree
class Solution
{
    int n;
    vector<int> bit;
    void update(int x)
    {
        //here -x is 2's complement of x and multiplying it with x gives the last set bit, then we add it with x 
        for(; x < n + 3; x += (x & -x))
            bit[x]++;
    }

    int query(int x)
    {
        int sum = 0;
        for(; x > 0; x -= (x & -x))
            sum += bit[x];
        return sum;
    }

public:
    int createSortedArray(vector<int> &v)
    {
        int ans = 0, mod = 1e9 + 7;
        n = v.size();
        bit = vector<int>(n + 3, 0);    //here it's n + 3 becoz the size of bit array must be n+1, so i simply went with +3
        for(int i = 0; i < n; i++)
        {
            ans = (ans + min(query(v[i] - 1), i - query(v[i]))) % mod;
            update(v[i]);
        }
        return ans;
    }
};





// Time complexity - O(NlogN)
// Space complexity - O(N) + auxiliary stack space

class Solution
{
    vector<int> sl, gl;
    int mod = 1e9 + 7;

    void mergeRemaining(vector<int> &v, int l, int mid, int r, int high, int low, int k, vector<int> &sorted)
    {
        while (l <= mid)
            sorted[k++] = v[l++];
        while (r <= high)
            sorted[k++] = v[r++];
        for (int i = low; i <= high; i++)
            v[i] = sorted[i - low];
    }

    void merge(vector<int> &v, vector<int> &inc, vector<int> &dec, int low, int mid, int high)
    {
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);
        while (l <= mid and r <= high)
            if (v[inc[l]] >= v[inc[r]])
                sorted[k++] = inc[l++];
            else
                sl[inc[r]] += mid - l + 1, sorted[k++] = inc[r++];
        mergeRemaining(inc, l, mid, r, high, low, k, sorted);

        l = low, r = mid + 1, k = 0;
        while (l <= mid and r <= high)
            if (v[dec[l]] <= v[dec[r]])
                sorted[k++] = dec[l++];
            else
                gl[dec[r]] += mid - l + 1, sorted[k++] = dec[r++];
        mergeRemaining(dec, l, mid, r, high, low, k, sorted);
    }

    void mergeSort(vector<int> &v, vector<int> &inc, vector<int> &dec, int low, int high)
    {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergeSort(v, inc, dec, low, mid);
        mergeSort(v, inc, dec, mid + 1, high);
        merge(v, inc, dec, low, mid, high);
    }

public:
    int createSortedArray(vector<int> &v)
    {
        if (v.size() == 1)
            return 0;

        vector<int> inc(v.size()), dec(v.size());
        sl = gl = inc;

        for (int i = 0; i < v.size(); i++)
            inc[i] = dec[i] = i;

        int ans = 0;
        mergeSort(v, inc, dec, 0, v.size() - 1);
        for (int i = 0; i < v.size(); i++)
            ans = (ans + min(sl[i], gl[i])) % mod;
        return ans;
    }
};


