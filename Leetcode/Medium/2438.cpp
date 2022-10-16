#include "../../headers.h"

class Solution
{
    int mod = 1e9 + 7;
public:
    vector<int> productQueries(int n, vector<vector<int>> &v)
    {
        vector<int> p, ans;
        for(int i = 0; i < 32; i++)
            if((n & (1 << i)) != 0)
                p.push_back(1 << i);

        for(auto q: v)
        {
            int i = q[0];
            long mul = p[i++];
            while(i <= q[1])
                mul = (mul * p[i++]) % mod;
            ans.push_back(mul);
        }
        return ans;
    }
};