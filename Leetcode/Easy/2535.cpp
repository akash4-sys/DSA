#include "headers.h"

class Solution
{
public:
    int differenceOfSum(vector<int> &v)
    {
        int x = 0, y = 0;
        for (int n : v)
        {
            x += n;
            for (; n; n /= 10)
                y += (n % 10);
        }
        return abs(x - y);
    }
};