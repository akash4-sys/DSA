#include "../../headers.h"

class Solution
{
public:
    int largestAltitude(vector<int> &v)
    {
        int ans = 0, alt = 0;
        for (int n : v)
            alt += n, ans = max(ans, alt);
        return ans;
    }
};