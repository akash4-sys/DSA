#include "../../headers.h"

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int ch[26] = {0}, ans = 0;
        for (char &c : s)
            ch[c - 'a']++;
        for (char &c : t)
            ch[c - 'a']--;
        
        for (int a : ch)
            ans += abs(a);
        return ans;
    }
};