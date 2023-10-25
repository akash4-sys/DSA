#include "../../headers.h"

class Solution
{
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& v, vector<int>& grp)
    {
        vector<string> ans = {v[0]};
        for (int i = 1, p = !grp[0]; i < v.size(); i++)
            if (grp[i] == p)
                ans.push_back(v[i]), p ^= 1;
        return ans;
    }
};