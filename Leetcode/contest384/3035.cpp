#include "../../headers.h"

class Solution
{
public:
    int maxPalindromesAfterOperations(vector<string> &words)
    {
        int ans = 0, pairs = 0;
        vector<int> length, ch(26, 0);
        for (auto &s : words)
        {
            length.push_back(s.size());
            for (auto &c : s)
                pairs += (++ch[c - 'a'] % 2 == 0);
        }

        sort(length.begin(), length.end());
        for (int len : length) {
            pairs -= (len / 2);
            ans += pairs >= 0;
        }
        return ans;
    }
};