#include "headers.h"

class Solution
{
public:
    int sumOfSquares(vector<int> &v)
    {
        int ans = 0, n = v.size();
        for (int i = 0; i < v.size(); i++)
            ans += (n % (i + 1) == 0) ? v[i] * v[i] : 0;
        return ans;
    }
};