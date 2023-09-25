#include "headers.h"

class Solution
{
public:
    string maximumOddBinaryNumber(string &s)
    {
        int ones = count(s.begin(), s.end(), '1'), n = s.size();
        string r(n, '0');
        for (int i = 0; i < ones - 1; i++)
            r[i] = '1';
        r.back() = '1';
        return r;
    }
};