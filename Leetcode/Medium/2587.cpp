#include "headers.h"

class Solution
{
public:
    int maxScore(vector<int> &v)
    {
        long long ans = 0, sum = 0;
        sort(v.begin(), v.end(), greater<int>());
        for (int n : v)
        {
            sum += n;
            ans += sum > 0;
        }
        return ans;
    }
};