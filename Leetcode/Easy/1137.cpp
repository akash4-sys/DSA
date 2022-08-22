#include "../../headers.h"

class Solution
{
public:
    int tribonacci(int n)
    {
        if(n == 0)
            return 0;
        int latest = 1, seclast = 1, last = 0, sum;
        for(int i = 3; i <= n; i++)
        {
            sum = latest + seclast + last;
            last = seclast;
            seclast = latest;
            latest = sum;
        }
        return latest;
    }
};