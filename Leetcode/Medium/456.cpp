#include "../../headers.h"

class Solution
{
public:
    bool find132pattern(vector<int> &v)
    {
        stack<pair<int, int>> st;
        int cmin = INT_MAX;
        for (int n : v)
        {
            for (; !st.empty() && st.top().first <= n; st.pop());
            if (st.size() && n > st.top().second)
                return 1;
            st.push({n, cmin});
            cmin = min(cmin, n);
        }
        return 0;
    }
};