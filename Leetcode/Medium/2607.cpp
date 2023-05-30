#include "headers.h"

class Solution
{
public:
    long long makeSubKSumEqual(vector<int> &v, int k)
    {
        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            multiset<int> st;
            for (int j = i; v[j] != 0; (j += k) %= v.size())
                st.insert(v[j]), v[j] = 0;
            int median = *next(st.begin(), st.size() / 2);
            for (int n : st)
                ans += abs(n - median);
        }
        return ans;
    }
};