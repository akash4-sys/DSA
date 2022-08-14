#include "../../headers.h"

class Solution
{
public:

    int factorial(int n)
    {
        if(n == 0)
            return 1;
        return n * factorial(n - 1);
    }

    int countSpecialNumbers(int n)
    {
        string s = to_string(n);
        int digits = s.length();

        if(digits > 10)
            return 0;

        int fact9 = factorial(9), ans = 0;
        while(digits--)
            ans += (9 * (fact9/ factorial(10 - digits)));
        return ans;
    }
};