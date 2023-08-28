#include "../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int longestEqualSubarray(vector<int> &v, int k)
    {
        int ans = 0, i = 0;
        unordered_map<int, int> mp;
        for (int j = 0; j < v.size(); j++)
        {
            ans = max(ans, ++mp[v[j]]);
            if (j - i + 1 - ans > k)
                --mp[v[i++]];
        }
        return ans;
    }
};


// Time Complexity - O(N)
// Space Complexiyt - O(N)

class Solution
{
    int sub(vector<int> &v, int k)
    {
        int del = 0, len = 1, j = 0;
        for (int i = 1; i < v.size(); i++)
        {
            del += (v[i] - v[i - 1] - 1);
            for (; del > k && j + 1 < v.size(); j++)
                del -= (v[j + 1] - v[j] - 1);
            len = max(len, i - j + 1);
        }
        return len;
    }

public:
    int longestEqualSubarray(vector<int> &v, int k)
    {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < v.size(); i++)
            mp[v[i]].push_back(i);

        int ans = 0;
        for (auto &[n, idx] : mp)
            ans = max(ans, sub(idx, k));
        return ans;
    }
};