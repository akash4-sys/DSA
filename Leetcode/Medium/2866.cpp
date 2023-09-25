#include "../../headers.h"

class Solution
{
    void monoStack(vector<int> &v, vector<long long> &st, long long &curr, int i, long long k)
    {
        while (st.size() > 1 && v[st.back()] > v[i])
        {
            int j = st.back();
            st.pop_back();
            curr -= (j - st.back()) * v[j] * k;
        }
        curr += (i - st.back()) * v[i] * k;
        st.push_back(i);
    }

public:
    long long maximumSumOfHeights(vector<int> &v)
    {
        long long ans = 0, n = v.size(), curr = 0;
        vector<long long> pf(n), st = {-1};
        for (int i = 0; i < n; i++)
            monoStack(v, st, curr, i, 1LL), pf[i] = curr;

        st = {n};
        curr = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            monoStack(v, st, curr, i, -1LL);
            ans = max(ans, pf[i] + curr - v[i]);
        }
        return ans;
    }
};