#include "../../headers.h"

class Solution
{
public:
    int numIdenticalPairs(vector<int> &v)
    {
        int a[101] = {0}, ans = 0;
        for (int n : v)
            a[n]++;
        
        for (int i = 1; i <= 100; i++)
            ans += a[i] * (a[i] - 1) / 2;
        return ans;
    }
};