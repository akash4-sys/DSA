#include "../../headers.h"

class Solution
{
public:
    string lastNonEmptyString(string s)
    {
        int ch[26] = {0};
        string ans = "";
        for (char &c : s)
            ch[c - 'a']++;
        
        int x = *max_element(ch, ch + 26);
        for (int i = s.size() - 1; i >= 0; i--)
            if (ch[s[i] - 'a'] == x) {
                ans = s[i] + ans;
                ch[s[i] - 'a']--;
            }
        return ans;
    }
};