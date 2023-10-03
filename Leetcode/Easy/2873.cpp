#include "../headers.h"

class Solution
{
public:
    long long maximumTripletValue(vector<int> &v)
    {
        long long ans = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++)
                for (int k = j + 1; k < v.size(); k++)
                {
                    long long val = (v[i] - v[j]);
                    val *= v[k] * 1LL;
                    ans = max(ans, val);
                }
        return ans;
    }
};