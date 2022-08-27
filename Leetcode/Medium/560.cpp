#include "../../headers.h"

class Solution
{
public:
    int subarraySum(vector<int> v, int k)
    {
        int ans = 0, sum  = 0;
        unordered_map<int, int> ump;
        ump[0] = 1;
        for(int n: v)
        {
            sum += n;
            int d = sum - k;
            ans += ump[d];
            ump[sum]++;
        }
        return ans;
    }
};