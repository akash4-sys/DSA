#include "../../headers.h"

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        double ans = 0;
        int n = a.size() + b.size();
        vector<int> v(n);
        merge(a.begin(), a.end(), b.begin(), b.end(), v.begin());
        if (n % 2 != 0)
            return v[((n + 1) / 2) - 1];
        ans = ((float)v[(n / 2) - 1] + v[(n / 2)]) / 2;
        return ans;
    }
};