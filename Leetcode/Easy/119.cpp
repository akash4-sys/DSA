#include "../../headers.h"

class Solution
{
public:
    vector<int> getRow(int n)
    {
        vector<int> ans = {1};
        for(int i = 1; i <= n; i++)
        {
            vector<int> temp(i+1, 1);
            for(int j = 1; j < i; j++)
                temp[j] = ans[j-1] + ans[j];
            ans = temp;
        }
        return ans;
    }
};