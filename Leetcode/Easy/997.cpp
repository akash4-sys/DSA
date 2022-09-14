#include "../../headers.h"

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &edges)
    {
        vector<int> mp(n + 1, 0);
        for (auto e : edges)
            mp[e[1]]++, mp[e[0]]--;
        
        for(int i = 1; i <= n; i++) 
            if(mp[i] == n - 1)
                return i;
        return -1;
    }
};