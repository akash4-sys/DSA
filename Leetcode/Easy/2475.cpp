#include "headers.h"

class Solution
{
public:
    int unequalTriplets(vector<int> &v)
    {
        unordered_map<int, int> cnt;
        for(int n: v)
            cnt[n]++;
        
        int ans = 0, left = 0, right = v.size();
        for(auto &[n, c]: cnt)
        {
            right -= c;
            ans += left * c * right;
            left += c;
        }
        return ans;
    }
};