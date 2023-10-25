#include "../../headers.h"

class Solution
{
public:
    vector<int> findIndices(vector<int> &v, int d, int x)
    {
        int mini = 0, maxi = 0, n = v.size();
        for (int i = d; i < n; i++)
        {
            if (v[i - d] < v[mini])
                mini = i - d;
            if (v[i - d] > v[maxi])
                maxi = i - d;
            if (v[i] - v[mini] >= x)
                return {mini, i};
            if (v[maxi] - v[i] >= x)
                return {maxi, i};
        }
        return {-1, -1};
    }
};


class Solution
{
public:
    vector<int> findIndices(vector<int> &v, int d, int x)
    {
        int n = v.size();
        vector<int> mn(n + 1, INT_MAX), mx(n + 1, INT_MIN), idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) -> bool {
            return v[a] < v[b];
        });
        sort(v.begin(), v.end());

        for (int i = n - 1; i >= 0; i--) {
            mn[i] = min(mn[i + 1], idx[i]);
            mx[i] = max(mx[i + 1], idx[i]);
        }

        for (int i = 0; i < n; i++)
        {
            int j = lower_bound(v.begin(), v.end(), v[i] + x) - v.begin();
            if (j < n)
            {
                if (abs(idx[i] - mn[j]) >= d)
                    return {idx[i], mn[j]};
                if (abs(idx[i] - mx[j]) >= d)
                    return {idx[i], mx[j]};
            }
        }
        return {-1, -1};
    }
};