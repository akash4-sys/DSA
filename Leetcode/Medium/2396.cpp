#include "headers.h"

class Solution
{
public:
    bool isStrictlyPalindromic(int n)
    {
        for(int i = 2; i < n - 1; i++)
        {
            string s;
            int x = n;
            while(x != 0)
            {
                int dig = x % i;
                string r;
                if(dig < 10)
                    r = '0' + dig;
                else
                    r = dig - 10 + 'A';
                s += r;
                x /= i;
            }
            string p = s;
            reverse(p.begin(), p.end());
            if(p != s)
                return false;
        }
        return true;
    }
};