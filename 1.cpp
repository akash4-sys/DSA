#include "headers.h"

class Solution
{
    int cm(int n, int k)
    {
        if (k > n)
            return k;
        n = n + k / 2;
        n = n - (n % k);
        return n;
    }

public:
    int findSmallestInteger(vector<int> &v, int k)
    {
        for (int &n : v)
        {
            if (n < 0)
            {
                int x = cm(-n, k);
                if (x < -n)
                    x += k;
                x += n;
                n = x;
            }
            else if (n - cm(n, k) >= 0)
                n -= cm(n, k);
        }

        int ans = 0;
        unordered_map<int, int> mp;
        set<int> st(v.begin(), v.end());
        while (st.size())
        {
            auto it = st.begin();
            int n = *it;
            if (mp.count(n))
            {
                mp[(n) + k]++;
                st.insert(n + k);
                continue;
            }
            mp[n] = 1;
            st.erase(it);
            if (ans != n)
                return ans;
            ans++;
        }
        return ans;
    }
};