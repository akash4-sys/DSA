#include "../../headers.h"

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &m, int k)
    {
        int ans = INT_MIN, rows = m.size(), cols = m[0].size();
        for (int l = 0; l < cols; l++)
        {
            vector<int> sum(rows, 0);
            for (int r = l; r < cols; r++)
            {
                int ksum = 0, currMax = INT_MIN;
                for (int c = 0; c < rows; c++)
                {
                    sum[c] += m[c][r];
                    ksum = max(ksum + sum[c], sum[c]);
                    currMax = max(currMax, ksum);
                }
                if (currMax <= k)
                {
                    ans = max(ans, currMax);
                    continue;
                }
                set<int> s = {0};
                int currSum = 0;
                for(int n: sum)
                {
                    currSum += n;
                    auto it = s.lower_bound(currSum - k);
                    if(it != s.end())
                        ans = max(ans, currSum - *it);
                    s.insert(currSum);
                }
            }
        }
        return ans;
    }
};