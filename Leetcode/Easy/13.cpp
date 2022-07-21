#include "../../headers.h"

class Solution
{
public:
    map<char, int> ump = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};

    int romanToInt(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if(ump[s[i]] < ump[s[i+1]])
            {
                ans += (ump[s[i+1]] - ump[s[i]]);
                i++;
                continue;
            }
            ans += ump[s[i]];
        }
        return ans;
    }
};