#include "../../headers.h"

class Solution
{
public:
    int accountBalanceAfterPurchase(int n)
    {
        int r = n % 10;
        if (!r)
            return 100  - n;
        return 100 - (r >= 5 ? ceil(n / 10.0) * 10 : floor(n / 10.0) * 10);
    }
};