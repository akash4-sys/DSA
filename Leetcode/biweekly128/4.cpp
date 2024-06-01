#include "../../headers.h"

class Solution
{
public:
    long long numberOfSubarrays(vector<int> &v)
    {
        unordered_map<int, int> cnt;
        vector<int> st;
        long long ans = v.size();
        for (int i = 0; i < v.size(); i++)
        {
            while (st.size() && v[st.back()] < v[i])
                cnt[v[st.back()]]--, st.pop_back();
            ans += cnt[v[i]];
            st.push_back(i);
            cnt[v[i]]++;
        }
        return ans;
    }
};