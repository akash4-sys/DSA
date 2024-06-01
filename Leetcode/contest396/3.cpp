#include "../../headers.h"

class Solution
{
public:
    int minAnagramLength(string s)
    {
        int ch[26] = {0}, ans = 0, g = 0;
        for (char &c : s)
            ch[c - 'a']++;
        for (int f : ch)
            g = gcd(g, f);
        for (int f : ch)
            ans += (f / g);
        return ans;
    }
};