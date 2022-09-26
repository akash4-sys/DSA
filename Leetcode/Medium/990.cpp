#include "../../headers.h"

class Solution
{
    int ch[26] = {0};
    int find(int x)
    {
        if(x != ch[x])
            ch[x]  = find(ch[x]);
        return ch[x];
    }

public:
    bool equationsPossible(vector<string> &v)
    {
        iota(ch, ch + 26, 0);
        for (string s : v)
            if (s[1] == '=')
                ch[find(s[0] - 'a')] = find(s[3] - 'a');
        for(string s: v)
            if(s[1] == '!' && find(s[0] - 'a') == find(s[3] - 'a'))
                return false;
        return true;
    }
};