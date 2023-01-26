#include "headers.h"

class Solution
{
public:
    long long minOperations(vector<int> &a, vector<int> &b, int k)
    {
        long long add = 0, sub = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i])
            {
                if (!k || abs(a[i] - b[i]) %k != 0)
                    return -1;
                add += max(0, (b[i] - a[i]) / k);
                sub += max(0, (a[i] - b[i]) / k);
            }

        return add != sub ? -1 : add;
    }
};