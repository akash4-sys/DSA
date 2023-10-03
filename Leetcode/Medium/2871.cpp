#include "../../headers.h"

class Solution
{
public:
    int maxSubarrays(vector<int> &v)
    {
        int score = 0, ans = 0;
        for (int n : v)
        {
            score = score ? score & n : n;
            ans += score == 0;
        }
        return max(1, ans);
    }
};