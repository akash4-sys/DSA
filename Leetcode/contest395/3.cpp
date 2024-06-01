#include "../../headers.h"

class Solution {
public:
    long long minEnd(int N, int k) {
        long long x = k;
        for (int n = N - 1, i = 0; n; i++)
            if (!(x & (1LL << i))) {
                x |= (n & 1LL) << i;
                n >>= 1;
            }
        return x;
    }
};