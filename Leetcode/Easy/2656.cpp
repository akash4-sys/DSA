#include "headers.h"

class Solution
{
public:
    int maximizeSum(vector<int> &v, int k)
    {
        int n = *max_element(v.begin(), v.end()), sum = 0;
        while (k--)
            sum += n, n++;
        return sum;
    }
};