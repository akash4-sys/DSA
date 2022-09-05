#include "../../headers.h"

class Solution
{
public:
    int findNumberOfLIS(vector<int> &v)
    {
        int n = v.size(), ans = 0, maxLis = 0;
        vector<int> lis(n, 1), cnt(n, 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(v[j] < v[i] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1, cnt[i] = cnt[j];
                    
                else if(v[j] < v[i] && lis[i] == lis[j] + 1)
                    cnt[i] += cnt[j];
            }
            if(lis[i] > maxLis)
                maxLis = lis[i], ans = cnt[i];
            else if(lis[i] == maxLis)
                ans += cnt[i];
        }
        return ans;
    }
};