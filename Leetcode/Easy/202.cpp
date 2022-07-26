#include "../../headers.h"

class Solution
{
public:
    bool isHappy(int n)
    {
        int num = 1;
        while (num > 0)
        {
            int sum = 0;
            if (n < 10 && n != 7 && n != 1)
                return false;
            while (n > 0)
            {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            if (sum == 1)
                return true;
            if (num == sum)
                return false;
            num = sum;
            n = sum;
        }
        return false;
    }
};