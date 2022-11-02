#include "../../headers.h"

class Solution
{
public:
    int bulbSwitch(int n)
    {
        int ans = 0;
        for(int i = 0; i * i <= n; i++, ans++);
        return ans;
        // return sqrt(n);
    }
};