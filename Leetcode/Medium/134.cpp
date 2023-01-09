#include "../../headers.h"

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int tot = 0, curr = 0, st = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            tot += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            if (curr < 0)
                st = i + 1, curr = 0;
        }
        return tot < 0 ? -1 : st;
    }
};


// Time Complexity - O(N^2) - TLE
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        for (int st = 0, n = gas.size(); st < n; st++)
        {
            if (gas[st] < cost[st])
                continue;
            int curr = gas[st] - cost[st] + gas[(st + 1) % n], dis = 1;
            for (int i = st + 1; (i % n) != st; i++)
            {
                if (curr < cost[i % n])
                    break;
                curr = curr - cost[i % n] + gas[(i + 1) % n];
                dis++;
            }
            if (dis == n)
                return st;
        }
        return -1;
    }
};


// Dynamic progamming approach tle
class Solution
{
    int n;
    bool solve(vector<int> &gas, vector<int> &v, vector<vector<int>> &dp, int st, int c, int i)
    {
        if (st == i % n)
            return 1;
        if (c < v[i % n])
            return 0;
        if (dp[st][i % n] != -1)
            return dp[st][i % n];
        return dp[st][i % n] = solve(gas, v, dp, st, c - v[i % n] + gas[(i + 1) % n], i + 1);
    }

public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &v)
    {
        n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            if (gas[i] >= v[i] && solve(gas, v, dp, i, gas[i] - v[i] + gas[(i + 1) % n], i + 1))
                return i;
        return -1;
    }
};

// @lc app=leetcode id=134 lang=cpp
