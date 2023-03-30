#include "../../headers.h"

// Time Complexity - O(NlogN)
// Space Complexity - O(logN)

class Solution
{
public:
    int maxSatisfaction(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int ans = 0, sum = 0;
        for (int i = v.size() - 1; i >= 0 && v[i] + sum > 0; i--)
            sum += v[i], ans += sum;
        return ans;
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(logN)

class Solution
{
public:
    int maxSatisfaction(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int co = 0;
            for (int j = i, t = 1; j < v.size(); j++, t++)
                co += (v[j] * t);
            ans = max(ans, co);
        }
        return ans;
    }
};