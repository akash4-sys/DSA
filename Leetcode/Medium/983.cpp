#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int mincostTickets(vector<int> &v, vector<int> &c)
    {
        unordered_set<int> st(v.begin(), v.end());
        vector<int> dp(366, 0);
        for (int i = 1; i <= 365; i++)
        {
            dp[i] = dp[i - 1];
            if (st.find(i) != st.end())
                dp[i] = min({dp[i - 1] + c[0], dp[max(0, i - 7)] + c[1], dp[max(0, i - 30)] + c[2]});
        }
        return dp[365];
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    int dp[366], t[3] = {1, 7, 30};
    int rec(vector<int> &v, vector<int> &c, int i)
    {
        if (i == v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for (int k = 0, j = i; k < 3; k++)
        {
            for (; j < v.size() && v[j] < v[i] + t[k]; j++);
            ans = min(ans, rec(v, c, j) + c[k]);
        }
        return dp[i] = ans;
    }

public:
    int mincostTickets(vector<int> &v, vector<int> &c)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, c, 0);
    }
};


// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

class Solution
{
    int dp[395][395], t[3] = {0, 6, 29};
    int rec(vector<int> &v, vector<int> &c, int i, int d)
    {
        if (i == v.size())
            return 0;
        if (dp[i][d] != -1)
            return dp[i][d];
        if (v[i] <= d)
            return rec(v, c, i + 1, d);
        int ans = INT_MAX;
        for (int j = 0; j < 3; j++)
            ans = min(ans, rec(v, c, i + 1, v[i] + t[j]) + c[j]);
        return dp[i][d] = ans;
    }

public:
    int mincostTickets(vector<int> &v, vector<int> &c)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, c, 0, 0);
    }
};