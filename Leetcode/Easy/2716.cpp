#include "headers.h"

class Solution
{
public:
    int minimizedStringLength(string s)
    {
        int ch[26] = {0};
        for (char c : s)
            ch[c - 'a']++;
        
        int ans = s.size();
        for (int i = 0; i < 26; i++)
            if (ch[i] > 1)
                ans -= --ch[i];
        return ans;
    }
};