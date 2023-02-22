#include "../../headers.h"

class Solution
{
public:
    int minImpossibleOR(vector<int> &v)
    {
        unordered_set<int> st(v.begin(), v.end());
        int ans = 1;
        for (; st.count(ans); ans <<= 1);
        return ans;
    }
};