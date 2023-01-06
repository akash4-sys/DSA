#include "../../headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
    int idx = 0;
    void generateLPS(vector<int> &lps, vector<int> &p)
    {
        for (int i = 1, j = 0; i < p.size();)
            if (p[i] == p[j])
                lps[i++] = ++j;
            else if (j)
                j = lps[j - 1];
            else
                i++;
    }

    pair<int, int> matchAt(vector<int> &v, vector<int> &p)
    {
        vector<int> lps(p.size(), 0);
        generateLPS(lps, p);
        for (int i = idx, j = 0; i < v.size();)
        {
            if (v[i] == p[j])
                i++, j++;
            if (j == p.size())
                return {i - j, i - 2};
            if (i < v.size() && v[i] != p[j])
                j ? j = lps[j - 1] : i++;
        }
        return {-1, -1};
    }

public:
    bool canChoose(vector<vector<int>> &grps, vector<int> &v)
    {
        int pen = -1;
        for (auto &p : grps)
        {
            auto [st, en] = matchAt(v, p);
            if (st <= pen)
                return 0;
            pen = idx = en;
        }
        return 1;
    }
};

// @lc app=leetcode id=1764 lang=cpp