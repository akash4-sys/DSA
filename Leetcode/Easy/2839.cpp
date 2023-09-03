#include "headers.h"

class Solution
{
public:
    bool canBeEqual(string s, string r)
    {
        if (s[0] != r[0])
            swap(s[0], s[2]);
        if (s[1] != r[1])
            swap(s[1], s[3]);
        return s == r;
    }
};