#include "../../headers.h"

class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int diff, int valDiff)
    {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + diff; j < nums.size(); j++)
                if (abs(nums[i] - nums[j]) >= valDiff)
                    return {i, j};
        return {-1, -1};
    }
};

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