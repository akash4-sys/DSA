#include "../headers.h"

class Solution
{
public:
    int minOperations(vector<int> &v, int k)
    {
        int cnt[51] = {0}, n = v.size(), i = n - 1;
        for (int j = 0; j < k; i--)
            j += v[i] <= k && cnt[v[i]]++ == 0;
        return n - i - 1;
    }
};