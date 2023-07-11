#include "../../headers.h"

class Solution
{
public:
    bool buddyStrings(string s, string g)
    {
        int ch[26] = {0}, neq = 0, sp = 0;
        for (char c : s)
            ch[c - 'a']++;    
        for (char c : g)
            ch[c - 'a']--;
        
        for (int i = 0; i < 26; i++)
            if (ch[i])
                return 0;
        
        for (int i = 0; i < s.size(); i++) {
            neq += s[i] != g[i];
            sp += (++ch[s[i] - 'a'] >= 2);
        }
        return !neq ? sp : neq == 2;
    }
};