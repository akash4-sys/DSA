#include "../../headers.h"

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &v)
    {
        long long ans = 0, c = 0;
        for (int n : v)
        {
            if (n)
            {
                ans += (c * (c + 1) / 2);
                c = 0;
                continue;
            }
            c++;
        }
        return ans + (c * (c + 1) / 2);
    }
};