#include "../../headers.h"

class Solution
{
public:
    int countOperations(int x, int y)
    {
        int ans = 0;
        for (; x && y; ans++)
            if (x >= y)
                x -= y;
            else
                y -= x;
        return ans;
    }
};