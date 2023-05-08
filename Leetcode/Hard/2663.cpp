#include "../../headers.h"

// Time Complexity - O(N*K), K <= 26
// Space Complexity - O(1)

class Solution
{
    char findCh(string &s, int k, char c, int i)
    {
        for (char ch = c; ch < k + 'a'; ch++)
            if ((i - 2 < 0 || s[i - 2] != ch) && (i - 1 < 0 || s[i - 1] != ch))
                return ch;
        return 'N';
    }

public:
    string smallestBeautifulString(string s, int k)
    {
        int n = s.size(), i;
        for (i = n - 1; i >= 0; i--)
            if (s[i] != k + '`')
            {
                char c = findCh(s, k, s[i] + 1, i);
                if (c == 'N')
                    continue;
                s[i] = c;
                break;
            }
        
        if (i < 0 && s[0] == k + '`')
            return "";
        
        for (int j = i + 1; j < n; j++)
        {
            char c = findCh(s, k, 'a', j);
            if (c == 'N')
                return "";
            s[j] = c;
        }
        return s;
    }
};