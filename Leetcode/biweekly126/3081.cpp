#include "../../headers.h"

class Solution
{
public:
    string minimizeStringValue(string s)
    {
        int ch[26] = {0};
        for (char &c : s)
            if (c != '?')
                ch[c - 'a']++;
        
        string r = "";
        for (char &c : s)
            if (c == '?')
            {
                int min_fq = INT_MAX, j = -1;
                for (int i = 0; i < 26; i++)
                    if (ch[i] < min_fq)
                        min_fq = ch[i], j = i;
                r += char(j + 'a');
                ch[j]++;
            }
        
        int i = 0;
        sort(r.begin(), r.end());
        for (char &c : s)
            if (c == '?')
                c = r[i++];
        return s;
    }
};