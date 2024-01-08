#include "../../headers.h"

class Solution
{
public:
    int minOperations(vector<int> &v, int k)
    {
        int x = 0, ans = 0;
        for (int a : v)
            x ^= a;
        
        for (int i = 0; i < 32; i++)
        {
            bool a = (x & (1 << i));
            bool b = (k & (1 << i));
            ans += (a != b);
        }
        return ans;
    }
};