#include "../../headers.h"

class Solution
{
public:
    string minWindow(string &s, string &t)
    {
        int ch[60] = {0}, l = -1, len = s.size() + 1, cnt = 0;
        for (char &c : t)
            ch[c - 'A']++;
        
        for (int i = 0, j = 0; i < s.size(); i++)
            for (cnt += --ch[s[i] - 'A'] >= 0; cnt == t.size(); j++)
            {
                if (len > i - j + 1)
                    len = i - j + 1, l = j;
                cnt -= ++ch[s[j] - 'A'] > 0;
            }
        return l == -1 ? "" : s.substr(l, len);
    }
};