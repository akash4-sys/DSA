#include "../../headers.h"

class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &h, vector<int> &v)
    {
        long long mod = 1e9 + 7, ans = 0;
        h.push_back(1), v.push_back(1);
        h.push_back(m), v.push_back(n);

        unordered_set<int> st;
        for (int i = 0; i < h.size(); i++)
            for (int j = 0; j < h.size(); j++)
                if (i != j)
                    st.insert(abs(h[i] - h[j]));

        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v.size(); j++)
                if (i != j && st.count(abs(v[i] - v[j])))
                    ans = max(ans, (long long)abs(v[i] - v[j]));
        return ans == 0 ? -1 : (ans * ans) % mod;
    }
};