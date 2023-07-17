#include "headers.h"

class Solution
{
public:
    int sumImbalanceNumbers(vector<int> &v)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            vector<int> cnt(v.size() + 2, 0);
            cnt[v[i]] = 1;
            int sum = 0;
            for (int j = i + 1; j < v.size(); j++)
            {
                cnt[v[j]] = 1;
                ans += sum;
            }
        }
        return ans;
    }
};