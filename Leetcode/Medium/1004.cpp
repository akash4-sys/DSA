#include "../../headers.h"

class Solution
{
public:
    int longestOnes(vector<int>& v, int k)
    {
        int ans = 0;
        for (int l = 0, r = 0; r < v.size(); r++)
        {
            k -= v[r] == 0;
            while(k < 0)
                k += v[l++] == 0;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};