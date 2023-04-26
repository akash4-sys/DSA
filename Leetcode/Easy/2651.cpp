#include "headers.h"

class Solution
{
public:
    int findDelayedArrivalTime(int a, int t)
    {
        int d = a + t;
        if (d >= 24)
            return d - 24;
        return d;
    }
};