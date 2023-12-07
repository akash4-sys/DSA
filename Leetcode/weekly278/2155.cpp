#include "../../headers.h"

class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &v)
    {
        int ones = count(v.begin(), v.end(), 1), mx = 0, zero = 0, one = ones;
        for (int i = 0; i <= v.size(); i++)
        {
            mx = max(mx, ones + zero);
            if (i < v.size())
                zero += v[i] == 0, ones -= v[i];
        }

        vector<int> ans;
        for (int i = 0, zero = 0; i <= v.size(); i++)
        {
            if (one + zero == mx)
                ans.push_back(i);
            if (i < v.size())
                zero += v[i] == 0, one -= v[i];
        }
        return ans;
    }
};