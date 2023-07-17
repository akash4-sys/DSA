#include "headers.h"

class Solution
{
public:
    int longestAlternatingSubarray(vector<int> &v, int t)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int j = i, x = 1;
            for (; j < v.size() && v[j] <= t; j++, x ^= 1)
                if ((x && v[j] % 2 != 0) || (!x && v[j] % 2 == 0))
                    break;
            ans = max(ans, j - i);
        }
        return ans;
    }
};