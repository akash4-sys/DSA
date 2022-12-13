#include "../../headers.h"

class Solution
{
public:
    int splitArray(vector<int> &v, int k)
    {
        int ans, l = 0, r = 0;
        for(int n : v)
            l = max(l, n), r += n;
        
        while(l <= r)
        {
            int mid = (l + r) / 2, c = 1, sum = 0;
            for(int n : v)
                if(sum + n <= mid)
                    sum += n;
                else c++, sum = n;
            if(c <= k)
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
};