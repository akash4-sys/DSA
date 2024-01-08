#include "../../headers.h"

class Solution
{
    int opToConvert(int n, int k)
    {
        int r = n % k;
        if (r <= k - r)
            return -r;
        return k - r;
    }

public:
    int minimumOperationsToMakeEqual(int x, int y)
    {
        if (x == y)
            return 0;
        if (!x || !y)
            return max(x, y);
        
        int ans = abs(x - y);
        int a = opToConvert(x, 5);
        int b = opToConvert(x, 11);

        if ((x + a) % 5 == 0)
            ans = min(ans, minimumOperationsToMakeEqual((x + a) / 5, y) + abs(a) + 1);
        if ((x + b) % 11 == 0)
            ans = min(ans, minimumOperationsToMakeEqual((x + b) / 11, y) + abs(b) + 1);
        return ans;
    }
};