#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int>& v, int k)
    {
        long long n = v.size(), sum = 0;
        vector<int> ans(n - k + 1, 0);
        for (int i = 0; i < k; i++) {
            int val = i ? v[i - 1] + 1 == v[i] : 1;
            sum += val;
        }

        ans[0] = sum == k ? v[k - 1] : -1;
        for (int i = 1; i <= n - k; i++) {
            int val1 = i ? v[i - 1] + 1 == v[i] : 1;
            int val2 = v[i + k - 2] + 1 == v[i + k - 1];
            sum -= val1;
            sum += val2;
            ans[i] = sum == k ? v[i + k - 1] : -1;
        }
        return ans;
    }
};