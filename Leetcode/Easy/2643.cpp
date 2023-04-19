#include "headers.h"

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &v)
    {
        int sum = 0, it = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int csum = accumulate(v[i].begin(), v[i].end(), 0);
            if (sum < csum)
                sum = csum, it = i;
        }
        return {it, sum};
    }
};