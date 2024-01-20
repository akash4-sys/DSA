#include "../../headers.h"

// Author me
// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    int sumSubarrayMins(vector<int> &nums)
    {
        long mod = 1e9 + 7, ans = 0, n = nums.size();
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums[i], i});
        sort(v.begin(), v.end());

        auto cnt = [&](long x){ return x * (x + 1) / 2; };
        set<int> st = {-1, (int)n};
        for (auto &a : v)
        {
            auto it = st.upper_bound(a[1]);
            long l = *prev(it) + 1, r = *it - 1;
            long m = r - l + 1, left = a[1] - l, right = r - a[1];
            long k = cnt(m) - (cnt(left) + cnt(right));
            // long x = (left * right) + left + right + 1;     // This one works as well
            st.insert(a[1]);
            ans = (ans + ((k * a[0]) % mod)) % mod;
        }
        return ans % mod;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int sumSubarrayMins(vector<int> &v)
    {
        long ans = 0, mod = 1e9 + 7, n = v.size();
        stack<int> st;
        for(int i = 0; i <= n; i++)
        {
            while(!st.empty() && v[st.top()] > (i == n ? INT_MIN : v[i]))
            {
                int j = st.top(); 
                st.pop();
                int k = st.empty() ? -1 : st.top();
                ans += (long)v[j] * (i - j) * (j - k);
            }
            st.push(i);
        }
        return ans % mod;
    }
};