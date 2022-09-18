#include "../../headers.h"

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int ans = 0;
        while(num)
            num = num % 2 ? num - 1 : num >> 2, ans++;
        return ans;
    }
};

class Solution
{
public:
    int numberOfSteps(int num)
    {
        return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
    }
};