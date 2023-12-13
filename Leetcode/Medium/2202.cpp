#include "../../headers.h"

class Solution
{
public:
    int maximumTop(vector<int> &v, int k)
    {
        int n = v.size();
        if (n == 1 && k % 2)
            return -1;
        
        if (k < 2)
            return v[k];
        if (k >= n)
            return *max_element(v.begin(), v.end() - (k == n));
        return max(v[k], *max_element(v.begin(), v.begin() + k - 1));
    }
};