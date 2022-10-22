#include "../../headers.h"

class Solution
{
public:
    int subsetXORSum(vector<int> &v)
    {
        int ans = 0;
        for(int n: v)
            ans |= n;
        return ans * (1 << (v.size() - 1));
    }
};


// Time Complexity O(N^2)
class Solution
{
public:
    int subsetXORSum(vector<int> &v)
    {
        int ans = 0;
        for(int i = 0; i < (1 << v.size()); i++)
        {
            int x = 0;
            for(int j = 0; j < v.size(); ++j)
                if(i & (1 << j))
                    x ^= v[j];
            ans += x;
        }
        return ans;
    }
};