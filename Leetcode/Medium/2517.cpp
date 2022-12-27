#include "headers.h"

class Solution
{
    bool check(vector<int> &v, int n, int k, int mid)
    {
        int count = 1, last_position = v[0];
        for (int i = 1; i < n; i++)
            if (v[i] - last_position >= mid)
            {
                last_position = v[i];
                count++;
                if (count == k)
                    return true;
            }
        return false;
    }

public:
    int maximumTastiness(vector<int> &v, int k)
    {
        sort(v.begin(), v.end());
        int n = v.size(),  i = 0, j = v[n - 1] - v[0], ans = 0;
        while (i <= j)
        {
            long long int mid = (i + j) / 2;
            if (check(v, n, k, mid))
                ans = mid, i = mid + 1;
            else
                j = mid - 1;
        }
        return ans;
    }
};