#include "headers.h"

class Solution
{
public:
    int xorAllNums(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size(), ans = 0;
        if (m % 2)
            ans ^= accumulate(a.begin(), a.end(), 0, bit_xor<int>());
        if (n % 2)
            ans ^= accumulate(b.begin(), b.end(), 0, bit_xor<int>());
        return ans;
    }
};