#include "../../headers.h"

class Solution
{
public:
    int change(int n, vector<int> &coins)
    {
        vector<int> v(n + 1, 0);
        v[0] = 1;

        for(auto c: coins)
            for(int i = c; i <= n; i++)
                v[i] += v[i - c];
        return v[n];
    }
};