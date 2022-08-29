#include "../../headers.h"

class Solution
{
public:
    int dodge(vector<int> &v, int st, int en)
    {
        int sum = 0, last = 0, lastLast = 0;
        for(int i = st; i < en; i++)
        {
            sum = max(last, lastLast + v[i]);
            lastLast = last;
            last = sum;
        }
        return sum;
    }

    int rob(vector<int> &v)
    {
        return max(dodge(v, 0, v.size()-1), dodge(v, 1, v.size()));
    }
};