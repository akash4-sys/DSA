#include "../../headers.h"

class Solution
{
    vector<long long> pf;
    long long operations(vector<int> &v, int i, int j)
    {
        int n = i - j + 1, m = (i + j) / 2;
        long long leftSum = pf[m] - (j ? pf[j - 1] : 0);
        long long rightSum = pf[i] - pf[m];
        return rightSum - leftSum + (n % 2 ? v[m] : 0);
    }

public:
    int maxFrequencyScore(vector<int> &v, long long k)
    {
        int ans = 0;
        sort(v.begin(), v.end());
        for (int a : v)
            pf.push_back((pf.size() ? pf.back() : 0) + a);

        for (int i = 0, j = 0; i < v.size(); i++)
        {
            for (; j < i && operations(v, i, j) > k; j++);
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};


class Solution
{
    vector<long long> pf;
    long long operations(vector<int> &v, int i, int j)
    {
        int m = (i + j) / 2;
        long long leftSum = pf[m] - (j ? pf[j - 1] : 0);
        long long rightSum = pf[i] - pf[m];
        long long leftOp = (1LL * (m - j + 1) * v[m]) - leftSum;
        long long rightOp = rightSum - (1LL * (i - m) * v[m]);
        return leftOp + rightOp;
    }

public:
    int maxFrequencyScore(vector<int> &v, long long k)
    {
        int ans = 0;
        sort(v.begin(), v.end());
        for (int a : v)
            pf.push_back((pf.size() ? pf.back() : 0) + a);

        for (int i = 0, j = 0; i < v.size(); i++)
        {
            while (j < i && operations(v, i, j) > k)
                j++;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};