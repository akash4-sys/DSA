#include "../../headers.h"

class Solution
{
public:
    int minimumPushes(string &s)
    {
        int ans = 0, n = s.size(), cost = 1;
        vector<int> ch(26, 0);
        for (char &c : s)
            ch[c - 'a']++;
        
        sort(ch.begin(), ch.end(), greater<int>());
        for (int i = 0; i < 26; i++)
        {
            ans += (cost * ch[i]);
            if ((i + 1) % 8 == 0)
                cost++;
        }
        return ans;
    }
};