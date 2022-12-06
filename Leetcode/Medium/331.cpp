#include "../../headers.h"

class Solution
{
public:
    bool isValidSerialization(string s)
    {
        if(s.empty())
            return 0;
        s += ',';
        int c = 1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ',')
                continue;
            c--;
            if(c < 0)
                return 0;
            if(s[i - 1] != '#')
                c += 2;
        }
        return !c;
    }
};