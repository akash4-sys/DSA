#include "../../headers.h"

class Solution
{
public:
    int maxSum(vector<int> &v, int k)
    {
        int n = v.size(), mod = 1e9 + 7, bits[32] = {0}, ans = 0;
        for (int x : v)
            for (int i = 0; i < 32; i++)
                if (x & (1 << i))
                    bits[i]++;
        
        for (int i = 0; i < k; i++)
        {
            int num = 0;
            for (int j = 0; j < 32; j++)
                if (bits[j])
                    num += (1 << j), bits[j]--;
            ans = (ans + ((1L * num * num) % mod)) % mod;
        }
        return ans;
    }
};