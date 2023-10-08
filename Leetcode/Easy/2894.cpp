#include "../../headers.h"

class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        int nums1 = 0, nums2 = 0;
        for (int i = 1; i <= n; i++)
            if (i % m )
                nums1 += i;
            else
                nums2 += i;
        return nums1 - nums2;
    }
};