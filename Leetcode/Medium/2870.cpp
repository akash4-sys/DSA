#include "../../headers.h"

class Solution
{
public:
    int minOperations(vector<int> &v)
    {
        unordered_map<int, int> mp;
        for (int n : v)
            mp[n]++;
        
        int ans = 0;
        for (auto [n, c] : mp) {
            if (c == 1)
                return -1;
            ans += (c / 3) + (c % 3 > 0);
        }
        return ans;
    }
};