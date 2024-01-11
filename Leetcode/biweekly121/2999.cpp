#include "../../headers.h"

// here dp is number of powerful integers of length i
// ! hard to understand the mathematical concept behind why we
// ! return 0 when current number is less that limit

class Solution
{
    long long dp[16] = {0};
    long long rec(string &n, string &s, int i, char limit)
    {
        if (n.size() < s.size())
            return 0;
        if (i == n.size() - s.size())
            return n.substr(i) >= s;
        
        int digits = min(limit, n[i]) - '1' + (i > 0);
        return dp[n.size() - i - 1] * digits + (n[i] < limit ? rec(n, s, i + 1, limit) : 0);
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        string low = to_string(start - 1), high = to_string(finish);
        for (int i = s.size(); i < high.size(); i++)
            dp[i] = i == s.size() ? 1 : dp[i - 1] * (limit + 1);
        return dp[high.size() - 1] + rec(high, s, 0, limit + '1') - dp[low.size() - 1] - rec(low, s, 0, limit + '1');
    }
};

// TLE
// Time Complexity - O(N)
// Space Complexity - O(N*N)

class Solution
{
    unordered_map<long long, long long> dp;
    long long rec(long long n, int limit, long long num, long long base)
    {
        if (num > n)
            return 0;
        if (dp.count(num))
            return dp[num];
        
        long long res = 1;
        for (int d = 1; d <= limit; d++)
        {
            long long curr = (base * d) + num, curr2 = base * d * 10 + num;
            res += rec(n, limit, curr, base * 10) + rec(n, limit, curr2, base * 100);
        }
        return dp[num] = res;
    }

public:
    long long numberOfPowerfulInt(long long low, long long high, int limit, string s)
    {
        int low_len = floor(log10(low) + 1), isLow = 0;
        long long base = 1, sf = stoll(s);
        for (int i = 1; i <= s.size(); i++)
            base *= 10;

        long long upper_limit = rec(high, limit, sf, base);
        long long lower_limit = rec(low, limit, sf, base);

        if (low_len > s.size())
            isLow = to_string(low).substr(low_len - s.size()) == s;
        return upper_limit - lower_limit + isLow;
    }
};

// TLE
// Time Complexity - O(N)
// Space Complexity - O(N*N)

class Solution
{
    long long rec(long long n, int len, int limit, string s)
    {
        if (s.size() == len)
            return 0;
        
        long long res = 0;
        for (char d = '0'; d <= limit + '0'; d++)
        {
            string r = d + s;
            if (stoll(r) <= n)
                res += rec(n, len, limit, r) + 1;
        }
        return res;
    }

public:
    long long numberOfPowerfulInt(long long low, long long high, int limit, string s)
    {
        int low_len = floor(log10(low) + 1), high_len = floor(log10(high) + 1), isLow = 0;
        long long upper_limit = rec(high, high_len,  limit, s);
        long long lower_limit = rec(low, low_len,  limit, s);

        if (low_len > s.size())
            isLow = to_string(low).substr(low_len - s.size()) == s;
        return upper_limit - lower_limit + isLow;
    }
};