#include "headers.h"

class Solution
{
public:
    int minOperations(vector<int> &v)
    {
        int n = v.size(), ans = INT_MAX;
        int one = count(v.begin(), v.end(), 1);
        if (one)
            return n - one;
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1, g = v[i]; j < n; j++)
            {
                g = gcd(v[j], g);
                if (g == 1)
                {
                    ans = min(ans, j - i);
                    break;
                }
            }
        return ans == INT_MAX ? -1 : ans + n - 1;
    }
};