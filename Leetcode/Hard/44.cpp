#include "../../headers.h"

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        if ((m > n && p.find("*") == string::npos) || n > m)
            return false;

        bool starEffect = false;
        int j = 0;
        for (int i = 0; i < m; i++)
        {
            if (s[i] == p[j])
            {
                j++;
            }
            else if (p[j] == '?')
            {
                j++;
            }
            else if (starEffect)
            {
                continue;
            }
            else if(p[j] == '*')
            {
                j += (j+1 < n);
            }
            else
                return false;
        }
        return true;
    }
};