#include "../../headers.h"

class Solution
{
public:
    long long interchangeableRectangles(vector<vector<int>> &rect)
    {
        map<pair<int, int>, long long> mp;
        long long ans = 0;
        for (auto &r: rect)
        {
            int g = gcd(r[0], r[1]);
            ans += mp[{r[0] / g, r[1] / g}]++;
        }
        return ans;
    }
};


// double is accurate only to a certain point which can cause trouble

class Solution
{
public:
    long long interchangeableRectangles(vector<vector<int>> &rect)
    {
        unordered_map<double, long long> ump;
        long long ans = 0;
        for (auto &r: rect)
            ans += ump[r[0] / (r[1] * 1.0)]++;
        return ans;
    }
};


class Solution
{
public:
    long long interchangeableRectangles(vector<vector<int>> &rect)
    {
        unordered_map<double, long long> ump;
        long long ans = 0;
        for (auto &r: rect)
            ump[r[0] / (r[1] * 1.0)]++;

        for (auto &[_, c]: ump)
            ans += ((c * (c + 1) / 2) - c);         // formula for subarray modified
        return ans;
    }
};