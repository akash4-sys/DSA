#include "../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    long long maximumTripletValue(vector<int> &v)
    {
        long long ans = 0, n = v.size();
        vector<int> pf(n, 0), sf(n, 0);
        for (int i = 0; i < n; i++)
            pf[i] = max(pf[i ? i - 1 : i], v[i]);
        
        for (int i = n - 1; i >= 0; i--)
            sf[i] = max(sf[i + 1 < n ? i + 1 : i], v[i]);
        
        for (int i = 1; i < n - 1; i++)
            ans = max(ans, 1LL * (pf[i - 1] - v[i]) * sf[i + 1]);
        return ans;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    long long maximumTripletValue(vector<int> &v)
    {
        long long ans = 0, mx = v[0];
        map<int, int> mp;
        for (int n : v)
            mp[n]++;

        if (--mp[v[0]] == 0)
            mp.erase(v[0]);
        for (int i = 1; i < v.size(); i++)
        {
            long long n = v[i];
            if (--mp[n] == 0)
                mp.erase(n);
            if (mx > n && mp.size())
                ans = max(ans, (mx - n) * mp.rbegin()->first);
            mx = max(mx, n);
        }
        return ans;
    }
};