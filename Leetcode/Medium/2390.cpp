#include "headers.h"

class Solution
{
public:
    string removeStars(string s)
    {
        int len = 0;
        for (char c : s)
        {
            if(c == '*')
                len = max(0, len - 1);
            else
                s[len++] = c;
        }
        s.resize(len);
        return s;
    }
};