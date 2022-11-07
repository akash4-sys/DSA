#include "../../headers.h"

#define ll long long
class Solution
{
public:
    ll minimumTotalDistance(vector<int> &v, vector<vector<int>> &f)
    {
        vector<vector<ll>> dp(v.size() + 1, vector<ll>(f.size() + 1, 1e16));
        sort(v.begin(), v.end());
        sort(f.begin(), f.end());
        for(int j = 0; j <= f.size(); j++)
            dp[0][j] = 0;

        for(int j = 1; j <= f.size(); j++)
            for(int i = 1; i <= v.size(); i++)
            {
                dp[i][j] = dp[i][j - 1];
                for(ll k = 1, sum = 0; k <= min(f[j - 1][1], i); k++)
                    sum += llabs(f[j - 1][0] - v[i - k]), dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + sum);
            }
        
        ll ans = 1e16;
        for(int j = 1; j <= f.size(); j++)
            ans = min(ans, dp[v.size()][j]);
        return ans;
    }
};

// Something is wrong somewhere
#define ll long long
class Solution
{
public:
    ll minimumTotalDistance(vector<int> &v, vector<vector<int>> &f)
    {
        sort(v.begin(), v.end());
        sort(f.begin(), f.end());
        vector<int> fl;
        for(auto n: f)
            while(n[1]--)
                fl.push_back(n[0]);

        vector<vector<ll>> dp(v.size() + 1, vector<ll>(fl.size() + 1, 1e16));
        dp[0][0] = 0;
        for(int i = 0; i < v.size(); i++)
            for(int j = 0; j < fl.size(); j++)
                dp[i + 1][j + 1] = min(abs(v[i] - fl[j]) + dp[i][j], dp[i + 1][j]);
        return dp[v.size()][fl.size()];
    }
};


#define ll long long
class Solution
{
    ll recurse(vector<vector<ll>> &dp, vector<int> &v, vector<int> &fl, int i, int j)
    {
        if(i >= v.size()) return 0;
        if(j >= fl.size()) return 1e16;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(abs(v[i] - fl[j]) + recurse(dp, v, fl, i + 1, j + 1), recurse(dp, v, fl, i, j + 1));
    }

public:
    ll minimumTotalDistance(vector<int> &v, vector<vector<int>> &f)
    {
        sort(v.begin(), v.end());
        sort(f.begin(), f.end());
        vector<int> fl;
        for(auto n: f)
            for(int i = n[1]; i; i--)
                fl.push_back(n[0]);
        vector<vector<ll>> dp(v.size(), vector<ll>(fl.size(), -1));
        return recurse(dp, v, fl, 0, 0);
    }
};


// Recursion TLE
#define ll long long
class Solution
{
    ll recurse(vector<int> &v, vector<int> &fl, int i, int j)
    {
        if(i >= v.size()) return 0;
        if(j >= fl.size()) return INT_MAX;
        return min(abs(v[i] - fl[j]) + recurse(v, fl, i + 1, j + 1), recurse(v, fl, i, j + 1));
    }

public:
    ll minimumTotalDistance(vector<int> &v, vector<vector<int>> &f)
    {
        sort(v.begin(), v.end());
        sort(f.begin(), f.end());
        vector<int> fl;
        for(auto n: f)
            for(int i = n[1]; i; i--)
                fl.push_back(n[0]);
        return recurse(v, fl, 0, 0);
    }
};

// @lc app=leetcode id=2463 lang=cpp