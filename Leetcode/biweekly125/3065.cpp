#include "../../headers.h"

class Solution
{
public:
    int minOperations(vector<int> &v, int k)
    {
        sort(v.begin(), v.end());
        int l = 0;
        while (l < v.size() && v[l] < k)
            l++;
        return l;
    }
};