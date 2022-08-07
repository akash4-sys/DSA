#include "../../headers.h"

class Solution
{
public:
    int countVowelPermutation(int n)
    {
        int mod = 1e9 + 7;
        long long ans = 5;
        vector<long long> curr(5, 1), prev(5, 1);

        for (int i = 1; i < n; i++)
        {
            curr[0] = (prev[1] + prev[2] + prev[4]) % mod;
            curr[1] = (prev[0] + prev[2]) % mod;
            curr[2] = (prev[1] + prev[3]) % mod;
            curr[3] = (prev[2]) % mod;
            curr[4] = (prev[2] + prev[3]) % mod;

            ans = (curr[0] + curr[1] + curr[2] + curr[3] + curr[4]) % mod;
            prev = curr;
        }

        return ans;
    }
};