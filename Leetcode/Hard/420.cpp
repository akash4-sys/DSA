#include "../../headers.h"

class Solution
{
public:
    int strongPasswordChecker(string s)
    {
        int up = 1, lo = 1, d = 1, n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'z')
                isupper(s[i]) ? up = 0 : lo = 0;
            d &= isdigit(s[i]) == 0;
        }

        int req = up + lo + d, rep = 0, oned = 0, twod = 0;
        if (n < 6)
            return max(req, 6 - n);

        for (int i = 0; i < n;)
        {
            int len = 1;
            for (; i + len < n && s[i + len] == s[i + len - 1]; len++);
            if (len >= 3)
            {
                rep += (len / 3);
                oned += (len % 3 == 0) ? 1 : 0;
                twod += (len % 3 == 1) ? 2 : 0;
            }
            i += len;
        }

        if (n <= 20)
            return max(req, rep);

        int del = n - 20;
        rep -= min(del, oned);
        rep -= min(max(del - oned, 0), twod) / 2;
        rep -= max(del - oned - twod, 0) / 3;
        return del + max(req, rep);
    }
};