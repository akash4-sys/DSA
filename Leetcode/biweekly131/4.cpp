#include "../../headers.h"

class BIT {
    int n;
    vector<int> bit;

public:
    BIT(int _n): n(_n), bit(_n, 0) {}

    int getMax(int i) {
        int x = 0;
        for (; i > 0; i -= i & (-i))
            x = max(x, bit[i]);
        return x;
    }

    void update(int i, int val) {
        for (; i < n; i += i & (-i))
            bit[i] = max(bit[i], val);
    }
};

class Solution
{
public:
    vector<bool> getResults(vector<vector<int>> &qrs)
    {
        BIT bit(50001);
        vector<bool> ans;
        set<int> st = {0};
        for (auto &q : qrs)
            if (q[0] == 1)
                st.insert(q[1]);
        
        for (auto it = next(begin(st)); it != end(st); it++)
            bit.update(*it, *it - *prev(it));
        
        for (int i = qrs.size() - 1; i >= 0; i--)
        {
            int type = qrs[i][0], x = qrs[i][1], k = qrs[i][0] == 2 ? qrs[i][2] : 0;
            auto it = st.lower_bound(x);
            if (type == 1) {
                if (next(it) != end(st))
                    bit.update(*next(it), *next(it) - *prev(it));
                st.erase(it);
            }
            else
                ans.push_back(x - *prev(it) >= k || bit.getMax(x) >= k);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};