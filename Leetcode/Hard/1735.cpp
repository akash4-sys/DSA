#include "../../headers.h"

int comb[10013][14] = {1};
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

class Solution
{
    int mod = 1e9 + 7;
    void preCalc()
    {
        if (comb[1][1])
            return;
        for (int n = 1; n < 10013; n++)
            for (int r = 0; r < 14; r++)
                comb[n][r] = !r ? 1 : (comb[n - 1][r - 1] + comb[n - 1][r]) % mod;
    }

public:
    vector<int> waysToFillArray(vector<vector<int>> &qrs)
    {
        preCalc();
        vector<int> ans;
        for (auto q : qrs)
        {
            int res = 1;
            for (auto p : primes)
            {
                int r = 0;
                for (; q[1] % p == 0; q[1] /= p, r++);
                res = ((long)res * comb[q[0] - 1 + r][r]) % mod;
            }
            if (q[1] != 1)
                res = ((long)res * q[0]) % mod;
            ans.push_back(res);
        }
        return ans;
    }
};


// Since integer values can be too big results in wrong answer
class Solution
{
    int mod = 1e9 + 7;
    vector<int> primeFactors(int n)
    {
        unordered_map<int, int> mp;
        if (n == 2)
            mp[n]++;
        for (int i = 2, sq = sqrt(n); i <= sq; i++)
            for (; !(n % i); n /= i)
                mp[i]++;
        if (n > 2)
            mp[n]++;

        vector<int> f;
        for (auto [_, c] : mp)
            f.push_back(c);
        return f;
    }

    long long fact(int x)
    {
        long long res = 1;
        for (long long i = 1; i <= x; i++)
            res = (res * i) % mod;
        return res;
    }

    int nCr(int n, int r)
    {
        return fact(n) / (fact(r) * fact(n - r));
    }

public:
    vector<int> waysToFillArray(vector<vector<int>> &qrs)
    {
        vector<int> ans;
        for (auto q : qrs)
        {
            auto fq = primeFactors(q[1]);
            long res = 1;
            for (int f : fq)
                res = (res * nCr(q[0] + f - 1, f)) % mod;
            ans.push_back(res);
        }
        return ans;
    }
};