#include "headers.h"

class Solution
{
    int maxs(vector<int> &nums)
    {
        int maxSum = INT_MIN, sum = 0;
        for (int n : nums)
        {
            maxSum = max(maxSum, sum + n);
            sum = max(sum + n, 0);
        }
        return maxSum;
    }

public:
    int maximumCostSubstring(string s, string r, vector<int> &v)
    {
        int ch[26] = {0};
        for (int i = 0; i < r.size(); i++)
            ch[r[i] - 'a'] = i + 1;

        vector<int> a;
        for (char c : s)
            if (ch[c - 'a'])
                a.push_back(v[ch[c - 'a'] - 1]);
            else
                a.push_back((c - 'a') + 1);
        
        return maxs(a);
    }
};