#include "../../headers.h"

class Solution
{
public:
    int minimumPushes(string &s)
    {
        int n = s.size(), r = n % 8, x = n / 8, ans = 0;
        for (int i = 1; i <= x; i++)
            ans += (i * 8);
        return ans + (r * (x + 1));
    }
};