#include "headers.h"

class Solution
{
public:
    string robotWithString(string s)
    {
        string ans = "", t = "";
        int ch[26] = {}, i = 0;
        for(auto c: s)
            ch[c - 'a']++;
        
        for(auto c: s)
        {
            t += c;
            ch[c - 'a']--;
            while(i < 26 && !ch[i])
                ++i;
            while(!t.empty() && t.back() - 'a' <= i)
                ans += t.back(), t.pop_back();
        }
        return ans;
    }
};