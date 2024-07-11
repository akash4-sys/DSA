#include "../../headers.h"

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> v(n, 1);
        int mod = 1e9 + 7;
        while (k--)
        {
            for (int i = 1; i < n; i++)
                (v[i] += v[i - 1]) %= mod;
        }
        return v[n - 1];
    }
};