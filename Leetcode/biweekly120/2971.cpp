#include "../../headers.h"

class Solution
{
public:
    long long largestPerimeter(vector<int> &v)
    {
        sort(v.begin(), v.end());
        long long ans = -1, sum = v[0] + v[1];
        for (int i = 2; i < v.size(); i++)
        {
            if (sum > v[i])
                ans = max(ans, sum + v[i]);
            sum += v[i];
        }
        return ans;
    }
};