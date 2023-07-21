#include "headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>> &v)
    {
        vector<long long> ans = {(m - 1LL) * (n - 1), 0, 0, 0, 0};
        unordered_map<long long, int> mp;

        for (auto &c : v)
            for (int i = c[0]; i < min(c[0] + 2, m); i++)
                for (long long j = c[1], l = 1e5; j < min(c[1] + 2, n); j++)
                    if (i && j)
                    {
                        ans[mp[i * l + j]]--;
                        ans[++mp[i * l + j]]++;
                    }
        return ans;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    int dirs[4][2] = {{-1, -1}, {-1, 0}, {0, 0}, {0, -1}};

public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>> &v)
    {
        vector<long long> ans(5);
        map<vector<int>, int> mp;
        for (auto &c : v)
            for (auto [dx, dy] : dirs)
            {
                int x = c[0] + dx, y = c[1] + dy;
                if (x >= 0 && x < m && y >= 0 && y < n)
                    mp[{x, y}]++;
            }

        int cnt = 0;
        for (auto &[it, c] : mp)
            if (it[0] < m - 1 && it[1] < n - 1 && c < 5)
                ans[c]++, cnt++;

        ans[0] = (1LL * (m - 1) * (n - 1)) - cnt;
        return ans;
    }
};

// @lc app=leetcode id=2768 lang=cpp