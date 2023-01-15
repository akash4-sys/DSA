#include "../../headers.h"

class Solution
{
public:
    string smallestEquivalentString(string s, string r, string p)
    {
        char ch[26] = {0};
        for (int i = 0; i < 26; i++)
            ch[i] = i + 'a';
        
        for (int i = 0; i < s.size(); i++)
        {
            char x = max(ch[s[i] - 'a'], ch[r[i] - 'a']);
            char y = min(ch[s[i] - 'a'], ch[r[i] - 'a']);
            for (int i = 0; i < 26; i++)
                if (ch[i] == x)
                    ch[i] = y;
        }

        for (int i = 0; i < p.size(); i++)
            p[i] = ch[p[i] - 'a'];
        return p;
    }
};