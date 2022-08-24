#include "../../headers.h"

class Solution
{
public:
    string parse(string s)
    {
        int len = 0;
        for(char c : s)
        {
            if(c == '#')
                len = max(len - 1, 0);
            else
                s[len++] = c;
        }
        s.resize(len);
        return s;
    }

    bool backspaceCompare(string s, string t)
    {
        return parse(s) == parse(t);
    }
};