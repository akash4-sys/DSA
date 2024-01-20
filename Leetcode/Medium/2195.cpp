#include "../../headers.h"

class Solution
{
public:
    long long minimalKSum(vector<int> &v, int k)
    {
        long long sum = (long long)k * (k + 1) / 2;
        for (int a : set<int>(v.begin(), v.end()))
            if (a <= k)
                sum -= a, sum += (++k);
        return sum;
    }
};


// Time Complexity - O(N*logN)
// Space Complexity - O(N)

class Solution
{
public:
    long long minimalKSum(vector<int> &v, int k)
    {
        sort(v.begin(), v.end());
        v.push_back(INT_MAX);
        long long sum = 0, l = 0;
        for (int i = 0; i < v.size() && k; i++)
        {
            long long n = min(max(v[i] - l - 1, 0LL), k * 1LL);
            long long r = l + n;
            sum += ((r * (r + 1) / 2) - (l * (l + 1) / 2));
            k -= n;
            l = v[i];
        }
        return sum;
    }
};