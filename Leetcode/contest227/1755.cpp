#include "../../headers.h"

// Meet In the Middle Technique

// Time Complexity - O((2^(N / 2)) * logN)
// Space Complexity - O((2 ^ (N / 2)) * logN)

class Solution
{
    set<int> allSums(vector<int> &v, int l, int r)
    {
        set<int> st = {0};
        for (int i = l; i < r; i++)
            for (int a : vector<int>(st.begin(), st.end()))
                st.insert(a + v[i]);
        return st;
    }

public:
    int minAbsDifference(vector<int> &v, int goal)
    {
        int n = v.size(), ans = INT_MAX;
        auto s1 = allSums(v, 0, n / 2);
        auto s2 = allSums(v, n / 2, n);

        for (int sum : s1)
        {
            int rem = goal - sum;
            auto it = s2.lower_bound(rem);
            if (it != s2.end())
                ans = min(ans, abs(rem - *it));
            if (it != s2.begin())
                ans = min(ans, abs(rem - *prev(it)));
        }
        return ans;
    }
};