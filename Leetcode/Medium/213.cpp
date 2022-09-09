#include "../../headers.h"


// Time Complexity - O(2N)
// Space Complexity - O(1)

class Solution
{
public:
    int dodge(vector<int> &v, int st, int en)
    {
        int sum = 0, last = 0, lastLast = 0;
        for (int i = st; i < en; i++)
        {
            sum = max(last, lastLast + v[i]);
            lastLast = last;
            last = sum;
        }
        return sum;
    }

    int rob(vector<int> &v)
    {
        return max(dodge(v, 0, v.size() - 1), dodge(v, 1, v.size()));
    }
};


// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
    void exchange(int &sum, int &l, int &ll, int x)
    {
        sum = max(l, ll + x);
        ll = l;
        l = sum;
    }

public:
    int rob(vector<int> &v)
    {
        int sum1 = 0, l1 = 0, ll1 = 0, sum2 = 0, l2 = 0, ll2 = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            exchange(sum1, l1, ll1, v[i]);
            if (i >= 1)
                exchange(sum2, l2, ll2, v[i]);
        }
        exchange(sum2, l2, ll2, v[v.size() - 1]);
        return max(sum1, sum2);
    }
};