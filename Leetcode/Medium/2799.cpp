#include "../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &v)
    {
        int n = unordered_set<int>(v.begin(), v.end()).size(), ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0, j = 0; i < v.size(); i++)
        {
            n -= mp[v[i]]++ == 0;
            while (!n)
                n += --mp[v[j++]] == 0;
            ans += i;
        }
        return ans;
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &v)
    {
        int n = unordered_set<int>(v.begin(), v.end()).size(), ans = 0;
        unordered_map<int, int> mp;
        for (int r = 0, l = 0; r < v.size(); r++)
        {
            mp[v[r]]++;
            for (; l <= r && mp.size() == n; l++)
            {
                if (--mp[v[l]] == 0)
                    mp.erase(v[l]);
                ans += (v.size() - r);
            }
        }
        return ans;
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &v)
    {
        int n = unordered_set<int>(v.begin(), v.end()).size(), ans = 0;
        unordered_map<int, int> mp;
        for (int r = 0; r < v.size(); r++)
        {
            mp[v[r]]++;
            ans += (mp.size() == n);
            unordered_map<int, int> t = mp;
            for (int l = 0; l <= r && t[v[l]] - 1 > 0 && t.size() == n; l++)
                ans++, t[v[l]]--;
        }
        return ans;
    }
};