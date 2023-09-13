#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    int candy(vector<int> &v)
    {
        int n = v.size(), ans = n;
        for (int i = 1; i < n;)
        {
            i += v[i] == v[i - 1];
            int inc = 0, dec = 0;
            for (; i < n && v[i] > v[i - 1]; i++)
                ans += ++inc;
            for (; i < n && v[i] < v[i - 1]; i++)
                ans += ++dec;
            ans -= min(inc, dec);
        }
        return ans;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int candy(vector<int> &v)
    {
        int n = v.size(), ans = 0;
        vector<int> cnt(n, 1);
        for (int i = 1; i < n; i++)
            if (v[i] > v[i - 1])
                cnt[i] += cnt[i - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] > v[i + 1])
                cnt[i] = max(cnt[i], cnt[i + 1] + 1);
            ans += cnt[i];
        }
        return ans + cnt[n - 1];
    }
};