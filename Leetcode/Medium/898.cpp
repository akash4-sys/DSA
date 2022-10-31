#include "../../headers.h"

class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &v)
    {
        unordered_set<int> ans, last, curr;
        for(int n: v)
        {
            curr = {n};
            for(int i: last)
                curr.insert(i | n);
            last = curr;
            ans.insert(last.begin(), last.end());
        }
        return ans.size();
    }
};