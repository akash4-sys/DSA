#include "../../headers.h"

class Solution
{
public:
    int countPairs(vector<int> &v, int t)
    {
        int ans = 0;
        sort(v.begin(), v.end());
        for (int l = 0, r = v.size() - 1; l < r;)
            if (v[l] + v[r] < t)
                ans += r - l, l++;
            else
                r--;
        return ans;
    }
};