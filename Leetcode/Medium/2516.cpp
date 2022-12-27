#include "headers.h"

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int ch[3] = {0}, n = s.size(), ans = n;
        for (char c : s)
            ch[c - 'a']++;
        
        if (ch[0] < k || ch[1] < k || ch[2] < k)
            return -1;

        for (int i = 0, j = 0, l = 0; i < n; i++)
        {
            ch[s[i] - 'a']--;
            l++;
            while (ch[s[i] - 'a'] < k)
                ch[s[j++] - 'a']++, l--;
            ans = min(ans, n - l);
        }
        return ans;
    }
};