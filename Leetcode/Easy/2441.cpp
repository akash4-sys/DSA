#include "../../headers.h"

class Solution
{
public:
    int findMaxK(vector<int> &v)
    {
        int a[2001] = {0}, ans = -1;
        for (int n : v)
        {
            if (a[1000 - n])
                ans = max(ans, abs(n));
            a[n + 1000]++;
        }
        return ans;
    }
};