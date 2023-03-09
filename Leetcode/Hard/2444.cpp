#include "../../headers.h"

class Solution
{
public:
    long long countSubarrays(vector<int>& v, int minK, int maxK)
    {
        long long ans = 0;
        int minPos = -1, maxPos = -1, j = -1;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] < minK || v[i] > maxK)
                j = i;
            if (v[i] == minK)
                minPos = i;
            if (v[i] == maxK)
                maxPos = i;
            ans += max(0, min(maxPos, minPos) - j);
        }
        return ans;
    }
};