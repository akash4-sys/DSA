#include "../../headers.h"

class Solution
{
public:
    int distanceTraveled(int x, int y)
    {
        return (x + min((x - 1) / 4, y)) * 10;
    }
};


class Solution
{
public:
    int distanceTraveled(int x, int y)
    {
        int i = 1;
        for (; i <= x; i++)
            if (i % 5 == 0 && y)
                x++, y--;
        return (i * 10) - 10;
    }
};