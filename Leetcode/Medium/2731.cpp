#include "../../headers.h"

// sum of abs diff between each pair

//  prefix sum
class Solution
{
public:
    int sumDistance(vector<int> &v, string s, int t)
    {
        long long ans = 0, mod = 1e9 + 7, sum = 0, n = v.size();
        for (int i = 0; i < n; i++)
            v[i] += s[i] == 'R' ? t : -t;

        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            (ans += (1LL * i * v[i]) - sum) %= mod;
            sum += v[i];
        }
        return ans;
    }
};


// suffix sum
class Solution
{
public:
    int sumDistance(vector<int> &v, string s, int t)
    {
        long long ans = 0, sum = 0, n = v.size(), mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            v[i] += s[i] == 'R' ? t : -t;
            sum += v[i];
        }

        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            sum -= v[i];
            long long diff = 1LL * v[i] * (n - i - 1);
            (ans += abs(sum - diff)) %= mod;
        }
        return ans;
    }
};