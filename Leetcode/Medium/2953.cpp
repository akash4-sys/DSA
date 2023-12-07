#include "../../headers.h"

// Time Complexity - O(N*26*26)
// Space Complexity - O(N / 26)

class Solution
{
public:
    int countCompleteSubstrings(string &s, int K)
    {
        int ans = 0, n = s.size();
        for (int k = K; k <= K * 26 && k <= n; k += K)
            for (int i = 0, ch[26] = {0}, j = -1; i < n; i++)
            {
                ch[s[i] - 'a']++;
                if (i - k >= 0)
                    ch[s[i - k] - 'a']--;
                if (i > 0 && abs(s[i] - s[i - 1]) > 2)
                    j = i;
                
                if (i - k + 1 >= max(j, 0))
                {
                    int res = 1;
                    for (int c = 0; c < 26; c++)
                        if (ch[c] != K && ch[c])
                            res = 0;
                    ans += res;
                }
            }
        return ans;
    }
};