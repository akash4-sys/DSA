#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> ans;
        sort(num.begin(), num.end());
        int N = num.size();
        for (int i = 0; i < N - 2; ++i)
        {
            if (i && num[i] == num[i - 1])
                continue;
            int st = i + 1, en = N - 1;
            while (st < en)
            {
                int sum = num[i] + num[st] + num[en];
                if (sum == 0)
                {
                    ans.push_back({num[i], num[st], num[en]});
                }
                if (sum <= 0)
                {
                    ++st;
                    while (st < en && num[st] == num[st - 1])
                        ++st;
                }
                if (sum >= 0)
                {
                    --en;
                    while (st < en && num[en] == num[en + 1])
                        --en;
                }
            }
        }
        return ans;
    }
};