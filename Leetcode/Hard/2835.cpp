#include "../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    int minOperations(vector<int> &v, int t)
    {
        long long ans = 0, cnt[31] = {0}, sum = 0;
        for (int n : v)
            cnt[(int)log2(n)]++, sum += n;

        if (sum < t)
            return -1;

        for (int i = 0; i < 30;)
        {
            if (t & (1 << i))
            {
                if (cnt[i])
                    cnt[i]--;
                else
                {
                    for (; i < 30 && !cnt[i]; i++, ans++);
                    cnt[i]--;
                    continue;
                }
            }
            cnt[i + 1] += (cnt[i]) / 2;
            i++;
        }
        return ans;
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(1)

class Solution
{
public:
    int minOperations(vector<int> &v, int t)
    {
        long long tot = accumulate(v.begin(), v.end(), 0LL), ans = 0;
        if (tot < t)
            return -1;

        sort(v.begin(), v.end());
        while (t > 0)
        {
            int n = v.back();
            v.pop_back();
            if (tot - n >= t)
                tot -= n;
            else if (n <= t)
                tot -= n, t -= n;
            else
                v.push_back(n / 2), v.push_back(n / 2), ans++;
        }
        return ans;
    }
};