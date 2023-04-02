#include "headers.h"

class Solution
{
public:
    int miceAndCheese(vector<int> a, vector<int> &b, int k)
    {
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
            a[i] -= b[i], ans += b[i];
        sort(a.begin(), a.end(), greater<int>());
        return ans + accumulate(a.begin(), a.begin() + k, 0);
    }
};