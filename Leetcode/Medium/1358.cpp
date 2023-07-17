#include "../../headers.h"

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int ch[3] = {-1, -1, -1}, ans = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            ch[s[i] - 'a'] = i;
            ans += *min_element(ch, ch + 3) + 1;
        }
        return ans;
    }
};


class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int ch[3] = {0}, ans = 0;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            ch[s[i] - 'a']++;
            while (ch[0] && ch[1] && ch[2])
                ch[s[j++] - 'a']--;
            ans += j;
        }
        return ans;
    }
};