#include "../../headers.h"

class Solution
{
public:
    long long findMaximumElegance(vector<vector<int>> &v, int k)
    {
        long long sum = 0, n = v.size(), types = 0;
        sort(v.begin(), v.end(), greater<vector<int>>());
        vector<int> cnt(n + 1, 0), dup;

        for (int i = 0; i < k; i++)
        {
            types += !cnt[v[i][1]];
            sum += v[i][0];
            if (cnt[v[i][1]])
                dup.push_back(v[i][0]);
            cnt[v[i][1]]++;
        }

        long long ans = sum + (types * types);
        for (int i = k; i < n && dup.size(); i++)
            if (!cnt[v[i][1]])
            {
                sum += v[i][0] - dup.back();
                cnt[v[i][1]]++;
                types++;
                dup.pop_back();
                ans = max(ans, sum + (types * types));
            }
        return ans;
    }
};