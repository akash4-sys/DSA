#include "../../headers.h"

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long ans = 0, cnt[30] = {};
        for(int n : unordered_set<int>(begin(nums), end(nums)))
        {
            int bits = __builtin_popcount(n);
            cnt[bits]++;
        }

        for(int i=1; i<30;i++)
        {
            for(int j=1; j<30;j++)
            {
                if(i + j >= k)
                    ans += (cnt[i] * cnt[j]);
            }
        }
        return ans;
    }
};
