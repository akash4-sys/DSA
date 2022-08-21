#include "headers.h"

class Solution
{
public:
    int minimumRecolors(string s, int k)
    {
        int ans = INT_MAX, c = 0, j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            c += s[i] == 'W';
            if ((i - j) + 1 == k)
            {
                ans = min(ans, c);
                c -= s[i] == 'W';
                j++;
            }
        }
        return ans;
    }
};