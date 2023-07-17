#include "headers.h"

class Solution
{
public:
    long long continuousSubarrays(vector<int> &v)
    {
        long long ans = 0;
        multiset<int> st;
        for (int i = 0, j = 0; i < v.size(); i++)
        {
            st.insert(v[i]);
            while (!st.empty() && *st.rbegin() - *st.begin() > 2)
                st.erase(st.find(v[j++]));
            ans += i - j + 1;
        }
        return ans;
    }
};