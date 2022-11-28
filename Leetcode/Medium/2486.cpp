#include "headers.h"

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int j = 0, ans = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(j < s.size() && s[i] == t[j])
                j++;
        }
        return t.size() - j;
    }
};