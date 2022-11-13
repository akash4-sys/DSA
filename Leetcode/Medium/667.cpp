#include "../../headers.h"

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans(n);
        int i = 0, l = 1, r = k + 1;
        while(i < k)
            ans[i++] = l++, ans[i++] = r--;
        if(l == r)
            ans[i++] = r;
        while(i < n)
            ans[i++] = i + 1;
        return ans;
    }
};