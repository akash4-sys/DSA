#include "../../headers.h"

class Solution
{
public:
    int minimumBoxes(int n)
    {
        int sum = 1, base = 1, row = 1;
        while (sum < n)
        {
            base += (++row);
            sum += base;
        }

        while (sum > n)
        {
            --base;
            sum -= (row--);
        }
        return base + (sum < n);
    }
};