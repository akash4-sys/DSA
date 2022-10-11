#include "../../headers.h"

class Solution
{
public:
    string breakPalindrome(string s)
    {
        for(int i = 0; i < s.size() / 2; i++)
            if(s[i] != 'a')
            {
                s[i] = 'a';
                return s;
            }
        s[s.size() - 1] = 'b';
        return s.size() < 2 ? "" : s;
    }
};