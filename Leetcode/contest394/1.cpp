#include "../../headers.h"

class Solution
{
public:
    int numberOfSpecialChars(string s)
    {
        int l[26] = {0}, u[26] = {0};
        for (char &c : s)
            if (islower(c))
                l[c - 'a'] = 1;
            else
                u[c - 'A'] = 1;
        
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += (l[i] == u[i] && l[i]);
        return cnt;
    }
};