#include "headers.h"

class Solution
{
    int rev(int n)
    {
        int r = 0;
        for(; n; n /= 10)
            r = (r * 10) + (n % 10);
        return r;
    }

public:
    bool sumOfNumberAndReverse(int n)
    {
        for(int i = n / 2; i <= n; i++)
            if(i + rev(i) == n)
                return true;
        return false;
    }
};


class Solution
{
public:
    bool sumOfNumberAndReverse(int n)
    {
        for (int i = 0; i <= n / 2; i++)
        {
            string s = to_string(i), r = to_string(n - i);
            while (s.size() < r.size())
                s = "0" + s;
            while (s.size() > r.size())
                r = "0" + r;
            reverse(s.begin(), s.end());
            if (r == s)
                return true;
        }
        return false;
    }
};