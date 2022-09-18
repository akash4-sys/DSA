#include "../../headers.h"

class Solution
{
public:
    vector<int> decode(vector<int> &v, int f)
    {
        vector<int> ans = {f};
        for(int n: v)
            ans.push_back(ans.back() ^ n);
        return ans;
    }
};