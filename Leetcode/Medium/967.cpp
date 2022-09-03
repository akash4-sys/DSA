#include "../../headers.h"

class Solution
{
    vector<int> ans;
    void dfs(int num, int n, int k)
    {
        if(n == 0)
            ans.push_back(num);
        else
        {
            int dig = num % 10;
            if(dig + k <= 9)
                dfs(num * 10 + dig + k, n - 1, k);
            if(k != 0 && dig - k >= 0)
                dfs(num * 10 + dig - k, n - 1, k);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k)
    {
        if (n == 1) 
            return { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        for (int i = 1; i <= 9; i++)
            dfs(i, n-1, k);
        return ans;
    }
};