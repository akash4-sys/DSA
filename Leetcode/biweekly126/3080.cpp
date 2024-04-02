#include "../../headers.h"

class Solution
{
public:
    vector<long long> unmarkedSumArray(vector<int> &v, vector<vector<int>> &qrs)
    {
        int n = v.size(), j = 0;
        long long sum = accumulate(v.begin(), v.end(), 0LL);
        vector<long long> ans, marked(n, 0);
        vector<vector<int>> vi;
        for (int i = 0; i < n; i++)
            vi.push_back({v[i], i});
        
        sort(vi.begin(), vi.end());
        for (auto q : qrs)
        {
            int idx = q[0], k = q[1];
            if (!marked[idx])
                sum -= v[idx], marked[idx] = 1;
            
            for (; j < n && k; j++)
                if (!marked[vi[j][1]])
                    sum -= vi[j][0], marked[vi[j][1]] = 1, k--;
            ans.push_back(sum);
        }
        return ans;
    }
};