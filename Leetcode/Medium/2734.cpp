#include "headers.h"

class Solution
{
public:
    string smallestString(string s)
    {
        int op = 0, i = 0;
        while (i < s.size() && s[i] == 'a')
            i++;
        for (; i < s.size() && s[i] != 'a'; i++)
            s[i]--, op = 1;
        if (!op)
            s.back() = 'z';
        return s;
    }
};