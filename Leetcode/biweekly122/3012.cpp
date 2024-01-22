#include "../../headers.h"

class Solution
{
public:
    int minimumArrayLength(vector<int> &v)
    {
        int x = *min_element(v.begin(), v.end()), cnt = 0, y = INT_MAX;
        for (int a : v) {
            if (a % x)
                y = min(y, a % x);
            cnt += a == x;
        }
        return y < x ? 1 : (cnt + 1) / 2;
    }
};