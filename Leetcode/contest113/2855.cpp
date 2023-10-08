#include "../../headers.h"

class Solution
{
public:
    int minimumRightShifts(vector<int> &v)
    {
        int ans = 0, n = v.size(), i = 1;
        for (; i < n && v[i] > v[i - 1]; i++);
        ans = n - i;
        
        if (i < v.size() && v[i] > v[0])
            return -1;
        for (i++; i < n; i++)
            if (v[i] > v[0] || v[i] < v[i - 1])
                return -1;
        return ans;
    }
};