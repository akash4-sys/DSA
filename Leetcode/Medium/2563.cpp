#include "headers.h"

class Solution
{
    long long countPair(vector<int> &v, int x)
    {
        long long ans = 0;
        for (int i = 0, j = v.size() - 1; i < j; i++)
        {
            while (i < j && v[i] + v[j] > x)
                --j;
            ans += j - i;
        }
        return ans;
    }

public:
    long long countFairPairs(vector<int> &v, int l, int r)
    {
        sort(v.begin(), v.end());
        return countPair(v, r) - countPair(v, l - 1);
    }
};



class Solution
{
public:
    long long countFairPairs(vector<int> &v, int l, int r)
    {
        long long i = v.size() - 1, ans = 0;
        sort(v.begin(), v.end());
        while (i > 0)
        {
            auto it1 = lower_bound(v.begin(), v.end(), l - v[i]);
            int start = it1 - v.begin();
            auto it2 = upper_bound(v.begin(), v.end(), r - v[i]);
            --it2;
            int end = it2 - v.begin();
            end = min((long long)end, i - 1);
            ans += (end - start >= 0) ? (end - start + 1) : 0;
            i--;
        }
        return ans;
    }
};