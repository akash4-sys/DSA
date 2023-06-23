#pragma once

#include <vector>
#include <algorithm>

using namespace std;

// https://real-statistics.com/descriptive-statistics/measures-central-tendency/weighted-mean-and-median/

class WeightedMedian
{
    long long convertToVal(vector<vector<long long>> &v, int val)
    {
        long long res = 0;
        for (int i = 0; i < v.size(); i++)
            res += (1LL * abs(v[i][0] - val) * v[i][1]);
        return res;
    }

public:
    long long minWeight(vector<int> &nums, vector<int> &weight)
    {
        long long n = nums.size(), sum = 0;
        vector<long long> pf;
        vector v(n, vector<long long>(2));

        for (int i = 0; i < n; i++)
            v[i] = {nums[i], weight[i]};
        
        sort(v.begin(), v.end());
        for (auto a : v)
            pf.push_back(sum += a[1]);
        
        long long k = lower_bound(pf.begin(), pf.end(), sum / 2) - pf.begin();
        long long ans = convertToVal(v, v[k][0]);

        if (pf[k] == sum / 2 && k + 1 < n)
            return min(ans, convertToVal(v, v[k + 1][0]));
        return ans;
    }
};