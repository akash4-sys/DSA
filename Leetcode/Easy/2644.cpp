#include "headers.h"

class Solution
{
public:
    int maxDivScore(vector<int> &v, vector<int> &d)
    {
        int ans = INT_MAX, s = 0;
        for (int n : d)
        {
            int c = 0;
            for (int x : v)
                c += (x % n == 0);
            if (s == c)
                ans = min(ans, n);
            if (s < c)
                ans = n, s = c;
        }
        return ans;
    }
};