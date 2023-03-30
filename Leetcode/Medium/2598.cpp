#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int findSmallestInteger(vector<int> &v, int k)
    {
        vector<int> mp(k, 0);
        for (int n : v)
            mp[((n % k) + k) % k]++;
        int stop = min_element(mp.begin(), mp.end()) - mp.begin();
        return (k * mp[stop]) + stop;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
public:
    int findSmallestInteger(vector<int> &v, int k)
    {
        map<int, int> mp;
        for (int n : v)
            mp[((n % k) + k) % k]++;
        
        int prev = -1;
        for (auto &[n, c] : mp)
        {
            if (prev + 1 != n)
                return prev + 1;
            for (int i = 1; i < c; i++)
                mp[n + (k * i)]++;
            prev = n;
        }
        return mp.rbegin()->first + 1;
    }
};