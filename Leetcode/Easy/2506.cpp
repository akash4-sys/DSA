#include "../../headers.h"

// Time Complexity - O(N ^ 2)
// Space Complexity - O(N)

class Solution
{
public:
    int similarPairs(vector<string> &v)
    {
        unordered_map<int, int> mp;
        for (auto s : v)
        {
            int a = 0;
            for(char c : s)
                a |= (1 << (c - 'a'));
            mp[a]++;
        }

        int ans = 0;
        for (auto [_, c] : mp)
            ans += c * (c - 1) / 2;
        return ans;
    }
};


class Solution
{
public:
    int similarPairs(vector<string> &v)
    {
        int ans = 0;
        for(int i = 0; i < v.size(); i++)
        {
            int a = 0;
            for(char c : v[i])
                a |= (1 << (c - 'a'));
            for(int j = i + 1; j < v.size(); j++)
            {
                int b = 0;
                for(char c : v[j])
                    b |= (1 << (c - 'a'));
                ans += a == b;
            }
        }
        return ans;
    }
};