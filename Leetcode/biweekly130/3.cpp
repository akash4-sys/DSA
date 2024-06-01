#include "../../headers.h"

class Solution
{
    int dp[1001] = {0};

    int rec(string &s, int i)
    {
        if (i == s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        int res = 1001, ch[26] = {0};
        unordered_map<int, int> mp;
        for (int j = i; j < s.size(); j++)
        {
            char c = s[j];
            mp[ch[c - 'a']]--;
            if (mp[ch[c - 'a']] <= 0)
                mp.erase(ch[c - 'a']);
            ch[c - 'a']++;
            mp[ch[c - 'a']]++;

            if (mp.size() == 1)
                res = min(res, rec(s, j + 1) + 1);
        }
        return dp[i] = res;
    }

public:
    int minimumSubstringsInPartition(string s)
    {
        memset(dp, -1, sizeof(dp));
        return rec(s, 0);
    }
};