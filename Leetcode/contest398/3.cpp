#include "../../headers.h"

class Solution
{
public:
    long long sumDigitDifferences(vector<int> &nums)
    {
        vector<string> v;
        for (int n : nums)
            v.push_back(to_string(n));
        
        long long ans = 0;
        for (int j = 0; j < v[0].size(); j++)
        {
            long long fq[10] = {0};
            for (int i = 0; i < v.size(); i++)
                fq[v[i][j] - '0']++;
            
            for (int i = 0; i <= 9; i++)
                for (int k = i + 1; k <= 9; k++)
                    ans += (fq[i] * fq[k]);
        }
        return ans;
    }
};