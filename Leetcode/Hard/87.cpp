#include "../../headers.h"

class Solution
{
    unordered_map<string, int> mp;
    bool check(string &s, string &r, int i, int len)
    {
        string p = s.substr(0, i), q = s.substr(i);
        return ((isScramble(p, r.substr(0, i)) && isScramble(q, r.substr(i))) || 
            (isScramble(p, r.substr(len - i)) && isScramble(q, r.substr(0, len - i))));
    }

public:
    bool isScramble(string s, string r)
    {
        if (s == r)
            return 1;
        if (mp.count(s + r))
            return mp[s + r];

        int len = s.size(), ch[26] = {0};
        for (int i = 0; i < s.size(); i++)
            ch[s[i] - 'a']++, ch[r[i] - 'a']--;

        for (int i = 0; i < 26; i++)
            if (ch[i])
                return 0;
            
        for (int i = 1; i < len; i++)
            if (check(s, r, i, len))
                return mp[s + r] = 1;
        return mp[s + r] = 0;
    }
};