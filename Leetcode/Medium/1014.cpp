#include "../../headers.h"

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &v)
    {
        int ans = 0, maxi = 0;
        for (int i = 0; i < v.size(); i++)
        {
            ans = max(ans, maxi + v[i] - i);
            maxi = max(maxi, v[i] + i);
        }
        return ans;
    }
};