#include "../../headers.h"

class Solution
{
public:
    int minCharacters(string &a, string &b)
    {
        int m = a.size(), n = b.size(), ans = m + n;
        vector<int> fa(26, 0), fb(26, 0);
        for (char &c : a)
            fa[c - 'a']++;
        for (char &c : b)
            fb[c - 'a']++;

        for (int i = 0; i < 26; i++)
        {
            ans = min(ans, m + n - fa[i] - fb[i]);
            if (i > 0)
                fa[i] += fa[i - 1], fb[i] += fb[i - 1];
            if (i < 25)
            {
                ans = min(ans, m - fa[i] + fb[i]);
                ans = min(ans, n + fa[i] - fb[i]);
            }
        }
        return ans;
    }
};