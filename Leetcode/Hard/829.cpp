#include "../../headers.h"

class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        long long sum = 1, ans = 0;
        for (int i = 1; sum <= n; i++, sum += i)
            ans += (n - sum) % i == 0;
        return ans;
    }
};

class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        unordered_map<long long, int> mp = {{0, 1}};
        long long sum = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i;
            mp[sum] = 1;
            ans += mp.count(sum - n);
        }
        return ans;
    }
};