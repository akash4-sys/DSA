#include "headers.h"

class Solution
{
public:
    int minIncrements(int n, vector<int> &v)
    {
        int ans = 0;
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            int l = (i * 2) + 1, r = (i * 2) + 2;
            ans += abs(v[l] - v[r]);
            v[i] += max(v[l], v[r]);
        }
        return ans;
    }
};