#include "../../headers.h"

class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        long long e1 = n / 2;
        long long e2 = m / 2;
        long long o1 = n % 2 == 0 ? n / 2 : (n / 2) + 1;
        long long o2 = m % 2 == 0 ? m / 2 : (m / 2) + 1;
        return (e1 * o2) + (e2 * o1);
    }
};