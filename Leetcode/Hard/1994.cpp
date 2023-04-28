#include "../../headers.h"

class Solution
{
    int mask[31] = {-1, 0, 1, 2, -1, 4, 3, 8, -1, -1, 5, 16, -1, 32, 9, 
        6, -1, 64, -1, 128, -1, 10, 17, 256, -1, -1, 33, -1, -1, 512, 7};
public:
    int numberOfGoodSubsets(vector<int> &v)
    {
        int dp[1025] = {1}, ans = 0, mod = 1e9 + 7, cnt[31] = {0};
        for (int n : v)
            cnt[n]++;
        
        for (int i = 2; i <= 30; i++)
            if (mask[i] > -1)
            {
                for (int curM = 0; curM < 1024; curM++)
                    if ((mask[i] & curM) == 0)
                        dp[mask[i] | curM] = (dp[mask[i] | curM] + (long long)cnt[i] * dp[curM]) % mod;
            }
        
        for (int i = 1; i < 1024; i++)
            (ans += dp[i]) %= mod;

        while (cnt[1]--)
            ans = (ans << 1) % mod;
        return ans;
    }
};


// Time Complexity - TLE
// Space Complexituy - O(N)

class Solution
{
    int goodPrime[31] = {0}, mod = 1e9 + 7;
    void primeFactors(int n)
    {
        int mask = 0, x = n;
        if (n == 2)
            mask |= (1 << n);

        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            for (; !(n % i); n /= i)
            {
                if (mask & (1 << i))
                    return;
                mask |= (1 << i);
            }
        
        if (n > 2 && mask & (1 << n))
            return;
        if (n > 2)
            mask |= (1 << n);
        goodPrime[x] = mask;
    }

    bool check(int pickedMask, int currMask)
    {
        for (int i = 2; i <= 30; i++)
            if ((pickedMask & (1 << i)) && (currMask & (1 << i)))
                return 0;
        return 1;
    }

    vector<unordered_map<int, int>> dp;
    int ways(vector<int> &v, int mask, int it)
    {
        if (it == v.size())
            return 0;
        if (dp[it].count(mask))
            return dp[it][mask];
            
        int res = 0;
        for (int i = it; i < v.size(); i++)
            if (goodPrime[v[i]] && check(mask, goodPrime[v[i]]))
                (res += ways(v, mask | goodPrime[v[i]], i + 1) + 1) %= mod;
        return dp[it][mask] = res;
    }

public:
    int numberOfGoodSubsets(vector<int> &v)
    {
        for (int i = 1; i <= 30; i++)
            primeFactors(i);

        dp = vector<unordered_map<int, int>>(v.size());
        int ans = ways(v, 0, 0), ones = count(v.begin(), v.end(), 1);
        while (ones--)
            ans = (ans << 1) % mod;
        return ans;
    }
};