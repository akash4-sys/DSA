#include "../../headers.h"

// different bounds
class Solution
{
    bool poss(vector<int> &v, int cap, int days)
    {
        int wt = 0, d = 1;
        for (int i = 0; i < v.size() && d <= days; wt += v[i++])
            if (wt + v[i] > cap)
                wt = 0, d++;
        return d <= days;
    }

public:
    int shipWithinDays(vector<int> &v, int days)
    {
        int l = 0, r = 0, ans = 0;
        for (int n : v)
            l = max(l, n), r += n;
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (poss(v, mid, days))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
};



// Time Complexity - O(Nlog(N))
// Space Complexity - O(1)
class Solution
{
    bool poss(vector<int> &v, int cap, int days)
    {
        int wt = 0, d = 1;
        for (int w : v)
        {
            if (w > cap)
                return 0;
            wt += w;
            if (wt > cap)
                d++, wt = w;
        }
        return d <= days;
    }

public:
    int shipWithinDays(vector<int> &v, int days)
    {
        int r = accumulate(v.begin(), v.end(), 0), l = 0, ans = 0;
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (poss(v, mid, days))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
};