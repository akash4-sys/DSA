#include "../../headers.h"

class Solution
{
public:
    int minimumAddedCoins(vector<int> &v, int n)
    {
        sort(v.begin(), v.end());
        long long ans = 0, sum = 0, i = 0;
        while (sum < n)
            if (i < v.size() && v[i] <= sum + 1)
                sum += v[i++];
            else
                sum += sum + 1, ans++;
        return ans;
    }
};