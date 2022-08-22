#include "../../headers.h"

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        while(i < t.length())
        {
            if(t[i] == s[j])
                j++;
            i++;
        }
        
        if(j == s.size())
            return true;
        return false;
    }
};