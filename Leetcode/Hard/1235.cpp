#include "../../headers.h"

class Solution
{
public:
    int jobScheduling(vector<int> &s, vector<int> &en, vector<int> &p)
    {
        vector<vector<int>> v;
        for (int i = 0; i < s.size(); i++)
            v.push_back({s[i], en[i], p[i]});

        sort(v.begin(), v.end());
        vector<int> dp(v.size() + 1, 0);
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int k = lower_bound(v.begin() + i, v.end(), vector<int>{v[i][1], -1, -1}, [&](auto &a, auto &b){
                return a[0] < b[0];
            }) - v.begin();
            dp[i] = max(dp[k] + v[i][2], dp[i + 1]);
        }
        return dp[0];
    }
};



class Solution
{
    int dp[50001];
    vector<vector<int>> v;

    int rec(int i)
    {
        if (i == v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        int k = lower_bound(v.begin() + i, v.end(), vector<int>{v[i][1], -1, -1}, [&](auto &a, auto &b){
            return a[0] < b[0];
        }) - v.begin();
        return dp[i] = max(rec(k) + v[i][2], rec(i + 1));
    }

public:
    int jobScheduling(vector<int> &s, vector<int> &en, vector<int> &p)
    {
        for (int i = 0; i < s.size(); i++)
            v.push_back({s[i], en[i], p[i]});

        sort(v.begin(), v.end());
        memset(dp, -1, sizeof(dp));
        return rec(0);
    }
};