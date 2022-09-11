#include "../../headers.h"

class Solution
{
public:
    int maxProduct(vector<int> &n)
    {
        int ans = n[0], l = 0, r = 0, sz = n.size() - 1;
        for (int i = 0; i <= sz; i++)
        {
            l = (l ? l : 1) * n[i];
            r = (r ? r : 1) * n[sz - i];
            ans = max({ans, l, r});
        }
        return ans;
    }
};