#include "../../headers.h"

class Solution
{
public:
    int countPalindromicSubsequence(string &s)
    {
        int n = s.size(), ans = 0;
        vector<int> l(26, INT_MAX), r(26, -1);
        for (int i = 0; i < n; i++) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = i;
        }

        for (int i = 0; i < 26; i++)
            if (l[i] < r[i])
                ans += unordered_set<char>(s.begin() + l[i] + 1, s.begin() + r[i]).size();
        return ans;
    }
};