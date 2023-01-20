#include "../../headers.h"

class Solution 
{
public:
    int addDigits(int n)
    {
        return (n - 1) % 9 + 1;
    }
};


class Solution 
{
public:
    int addDigits(int n)
    {
        while (to_string(n).size() != 1)
        {
            int x = 0;
            for (; n; n /= 10)
                x += n % 10;
            n = x;
        }
        return n;
    }
};