#include "headers.h"

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    long long maxStrength(vector<int> &v)
    {
        sort(v.begin(), v.end());
        long long ans = 1, c = 0;
        for (int i = 0; i < v.size(); i++)
            if (ans * v[i] > 0 || (i + 1 < v.size() && v[i + 1] < 0))
            {
                ans *= v[i];
                c++;
            }
        return c ? ans : v.back();
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    long long maxStrength(vector<int> &v)
    {
        if (v.size() == 1)
            return v[0];

        long long ans = 1, neg = 0, one = 0;
        sort(v.begin(), v.end());
        for (int n : v)
        {
            neg += (n < 0);
            one += (n == 1);
            if (n > 0)
                ans *= n;
        }

        neg -= (neg % 2 != 0);
        for (int i = 0; i < neg; i++)
            ans *= v[i];

        if (!one && ans == 1)
            return 0;
        return ans;
    }
};