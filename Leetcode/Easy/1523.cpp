#include "../../headers.h"

class Solution 
{
public:
    int countOdds(int l, int r)
    {
        return (r % 2) + (r / 2) - (l / 2);
    }
};