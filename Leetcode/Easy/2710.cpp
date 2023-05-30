#include "headers.h"

class Solution
{
public:
    string removeTrailingZeros(string s)
    {
        string r = "";
        while (s.size() && s.back() == '0')
            s.pop_back();
        return s;
    }
};