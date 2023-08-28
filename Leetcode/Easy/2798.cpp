#include "../headers.h"

class Solution
{
public:
    int numberOfEmployeesWhoMetTarget(vector<int> &v, int t)
    {
        int ans = 0;
        for (int &h : v)
            ans += h >= t;
        return ans;
    }
};