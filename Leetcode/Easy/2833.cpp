#include "../headers.h"

class Solution
{
public:
    int furthestDistanceFromOrigin(string s)
    {
        int l = 0, r = 0, u = 0;
        for (char &c : s)
            l += c == 'L', r += c == 'R', u += c == '_';
        return l >= r ? l + u - r : r + u - l;
    }
};