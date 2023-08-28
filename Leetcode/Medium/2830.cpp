#include "../headers.h"

class Solution
{
    int solve(vector<vector<int>> &offers, vector<int> &memo, int i)
    {
        if (i == offers.size()) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }

        auto j = upper_bound(begin(offers) + i, end(offers), offers[i][1], [](int t, const auto &vec) {
            return vec[0] > t;
        }) - begin(offers);
        return memo[i] = max(solve(offers, memo, i + 1), solve(offers, memo, j) + offers[i][2]);
    }

public:
    int maximizeTheProfit(int n, vector<vector<int>> &offers)
    {
        vector<int> memo(offers.size(), -1);
        sort(offers.begin(), offers.end());
        return solve(offers, memo, 0);
    }
};