#include "../../headers.h"

class Solution
{
public:
    int arraySign(vector<int> &v)
    {
        int ans = 1;
        for (int n : v)
            if (n < 0)
                ans *= -1;
            else if (n == 0)
                ans = 0;
        return ans;
    }
};