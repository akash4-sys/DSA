#include "headers.h"

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b)
    {
        vector<int> ans, cnt(a.size() + 1);
        for (int i = 0; i < a.size(); i++)
        {
            cnt[a[i]]++;
            cnt[b[i]]++;
            int n = 0;
            for (int j = 0; j <= a.size(); j++)
                n += (cnt[j] == 2);
            ans.push_back(n);
        }
        return ans;
    }
};