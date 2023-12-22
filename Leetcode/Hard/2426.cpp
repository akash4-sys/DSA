#include "../../headers.h"

class BIT
{
    vector<int> bit;
    int n;

public:
    BIT(int _n): n(_n), bit(_n, 0) {}

    int sum(int i)
    {
        int sum = 0;
        for (; i > 0; i -= i & (-i))
            sum += bit[i];
        return sum;
    }

    void update(int i)
    {
        for (; i < n; i += i & (-i))
            bit[i]++;
    }
};

class Solution
{
public:
    long long numberOfPairs(vector<int> &a, vector<int> &b, int d)
    {
        long long ans = 0, k = 30000;
        BIT bit(60001);
        for (int i = 0; i < a.size(); i++)
        {
            int curr = a[i] - b[i] + d + k;
            ans += bit.sum(curr);
            bit.update((a[i] - b[i]) + k);
        }
        return ans;
    }
};