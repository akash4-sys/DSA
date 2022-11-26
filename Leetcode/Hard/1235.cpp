#include "../../headers.h"

struct Job
{
    int s, f, p;
};

class Solution
{
    vector<Job> jobs;
    int nonConflicting(int i)       // to optimize it even further do binary search over here
    {
        for(int j = i - 1; j >= 0; j--)
            if(jobs[j].f <= jobs[i].s)
                return j;
        return -1;
    }

public:
    int jobScheduling(vector<int> &st, vector<int> &et, vector<int> &p)
    {
        for(int i = 0; i < st.size(); i++)
            jobs.push_back({st[i], et[i], p[i]});
        sort(jobs.begin(), jobs.end(), [&](Job &x, Job &y) { 
            return x.f < y.f;
        });

        vector<int> dp(jobs.size(), -1);
        dp[0] = jobs[0].p;
        for(int i = 1; i < jobs.size(); i++)
        {
            int it = nonConflicting(i), c = jobs[i].p;
            if(it != -1)
                c += dp[it];
            dp[i] = max(c, dp[i - 1]);
        }
        return dp.back();
    }
};


class Solution
{
    vector<Job> jobs;
    vector<int> dp;
    int nonConflicting(int i)
    {
        for(int j = i - 1; j >= 0; j--)
            if(jobs[j].f <= jobs[i].s)
                return j;
        return -1;
    }

    int maxProfit(int i)
    {
        if(i < 0)
            return 0;
        if(!i)
            return jobs[i].p;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(jobs[i].p + maxProfit(nonConflicting(i)), maxProfit(i - 1));
    }

public:
    int jobScheduling(vector<int> &st, vector<int> &et, vector<int> &p)
    {
        for(int i = 0; i < st.size(); i++)
            jobs.push_back({st[i], et[i], p[i]});
        sort(jobs.begin(), jobs.end(), [&](Job &x, Job &y) { 
            return x.f < y.f;
        });
        dp = vector<int>(jobs.size(), -1);
        return maxProfit(jobs.size() - 1);
    }
};

// @lc app=leetcode id=1235 lang=cpp