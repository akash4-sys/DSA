#include "../../headers.h"

class Solution
{
public:
    double average(vector<int> &v)
    {
        double mini = INT_MAX, maxi = 0.0, sum = 0.0, n = v.size();
        for (int a : v)
        {
            mini = min(mini, a * 1.0);
            maxi = max(maxi, a * 1.0);
            sum += a;
        }
        return (sum - mini - maxi) / (n - 2.0);
    }
};